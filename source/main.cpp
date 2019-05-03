// main.cpp

#include <iostream>
#include <memory>
#include <string>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "category.hpp"
#include "task.hpp"
#include "task_grid.hpp"
#include "scheduler.hpp"

enum class AppMode
{
    TASK_GRID_VIEW, // View Tasks on a Grid
    CALENDAR_VIEW,  // View Tasks on a Calendar @TODO
    NEW_TASK,       // Place Task on Grid
    TASK_DETAILS,   // Update task meta data
    ADD_CATEGORY,   // Create new category @TODO
    DELETE_PROMPT   // Prompt for Delete Task
};

// Unable to define Default Category in Category.cpp
void defineDefaultCategory()
{
    Category::Default = std::make_shared<Category>();
    Category::Default->setName("Default");

    auto unfocused = std::make_unique<sf::CircleShape>(5.0);
    unfocused->setFillColor(sf::Color::Red);
    unfocused->setPointCount(3);
    Category::Default->setUnfocusedDrawable(std::move(unfocused));

    auto focused = std::make_unique<sf::CircleShape>(5.0);
    focused->setFillColor(sf::Color::Red);
    focused->setPointCount(3);
    focused->setOutlineColor(sf::Color::Yellow);
    focused->setOutlineThickness(2.0);
    Category::Default->setFocusedDrawable(std::move(focused));
}


int main()
{
    // ****************************************************************
    // APP INITIALIZATION
    // ****************************************************************
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "YATM: Yet Another Task Manager");
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    // App Mode
    AppMode mode = AppMode::TASK_GRID_VIEW;
    bool displayHelpWindow = false;
    std::cout << "TASK_GRID_VIEW" << std::endl;

    // Define Default Category
    defineDefaultCategory();

    // @TODO - Load existing task list from file
    std::vector<Task> tasklist{};
    auto selectedId = 0; // <- Used for focusing tasks

    // Setup TaskGrid
    auto bounds = sf::FloatRect(0.0, 0.0, 600.0, 600.0);
    TaskGrid grid = TaskGrid(bounds);

    // Used by ImGui
    sf::Clock deltaClock;


    // ****************************************************************
    // GAME LOOP
    // ****************************************************************

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Let ImGui process events too
            ImGui::SFML::ProcessEvent(event);

            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // Resize window event
            else if (event.type == sf::Event::Resized)
            {
                // @TODO - Need to update View and ImGui Widgets Size
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    mode = AppMode::TASK_GRID_VIEW;
                    std::cout << "TASK_GRID_VIEW" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::F1)
                {
                    // Toggle Display Help Window
                    displayHelpWindow = !displayHelpWindow;
                }
                else if (event.key.code == sf::Keyboard::Q)
                {
                    mode = AppMode::NEW_TASK;
                    std::cout << "NEW_TASK" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Delete ||
                         event.key.code == sf::Keyboard::BackSpace)
                {
                    mode = AppMode::DELETE_PROMPT;
                    std::cout << "DELETE_PROMPT" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::W)
                {
                    mode = AppMode::TASK_DETAILS;
                    std::cout << "TASK_DETAILS" << std::endl;
                }
            }
            // Mouse Click
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                auto x = event.mouseButton.x;
                auto y = event.mouseButton.y;

                if (event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    // If mouse click is within bounds
                    auto isOnGrid = grid.contains(x, y);
                    if (isOnGrid)
                    {
                        if (mode == AppMode::NEW_TASK)
                        {
                            tasklist.emplace_back();
                            auto urgVsImp = grid.getUrgVsImp(x, y);

                            // selected points to the newly created element
                            auto selected =  std::prev(tasklist.end());

                            selected-> urgency = urgVsImp.x;
                            selected-> importance = urgVsImp.y;
                            selectedId = selected-> getId();
                        }
                        else
                        {
                            // @TODO - Select a task if close enough
                        }
                    }
                }
            }
        }


        // Imgui Update() Required
        ImGui::SFML::Update(window, deltaClock.restart());

        // Adjust schedule
        sortByHighestPriority(tasklist);

        // Provide iterator to selected Task in tasklist
        auto selected = std::find_if(tasklist.begin(),
                         tasklist.end(),
                         [&](const auto & task){
                            return task.getId() == selectedId;
                         });


        // ************************************************************
        // ImGui Windows and Such
        // ************************************************************

        // *** Menu bar
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::MenuItem("Help", "F1", displayHelpWindow))
            {
                displayHelpWindow = true;
            }
            ImGui::EndMainMenuBar();

        }
        if (displayHelpWindow)
        {
            ImGui::SetNextWindowBgAlpha(0.9f); // Transparent background
            if (ImGui::Begin("Help", &displayHelpWindow, ImGuiWindowFlags_NoCollapse))
            {
                ImGui::TextUnformatted("F1 - Display this message\nQ - Enter 'Insert Task Mode'\nW - Look at selected task's details\nDelete - Delete selected task\nEscape - Enter 'Task Grid View'");
                ImGui::End();
            }
            else
            {
                displayHelpWindow = false;
            }
        }


        // *** The following ImGui windows need a nonempty tasklist and focused task

        if (tasklist.empty() || selectedId == 0)
        {
            // Do nothing
        }
        else if (mode == AppMode::DELETE_PROMPT)
        {
            ImGui::SetNextWindowPos(ImVec2(200, 200), ImGuiCond_FirstUseEver);
            ImGui::SetNextWindowBgAlpha(0.9f); // Transparent background
            ImGui::Begin("Delete Prompt", 0, ImGuiWindowFlags_NoResize);
            ImGui::Text("Are you sure you want to delete the task: ");

            ImGui::PushID(&selected);
            auto name = selected->name;

            // TextUnformatted(char * begin, char * end)
            ImGui::TextUnformatted(name.c_str(), name.c_str() + name.size());
            ImGui::PopID();

            if(ImGui::Button("No"))
            {
                mode = AppMode::TASK_GRID_VIEW;
                std::cout << "TASK_GRID_VIEW" << std::endl;
            }
            ImGui::SameLine();
            if(ImGui::Button("Yes"))
            {
                tasklist.erase(selected);

                // selected points to end (so no focus)
                selected = tasklist.end();
                mode = AppMode::TASK_GRID_VIEW;
                std::cout << "TASK_GRID_VIEW" << std::endl;
            }
            ImGui::End(); // End "Delete Prompt"
        }
        else if (mode == AppMode::TASK_DETAILS)
        {
            ImGui::SetNextWindowPos(ImVec2(200, 200), ImGuiCond_FirstUseEver);
            ImGui::SetNextWindowBgAlpha(0.9f); // Transparent background
            ImGui::Begin("Task Details");

            auto id = selected->getId();
            auto name = selected->name;
            auto importance = selected->importance;
            auto urgency = selected->urgency;
            auto dueDateDay = selected->getDueDate().getDate()[0];
            auto dueDateMonth = selected->getDueDate().getDate()[1];
            auto dueDateYear = selected->getDueDate().getDate()[2];
            auto durationHours = selected->getDuration().getTime()[0];
            auto durationMinutes = selected->getDuration().getTime()[1];
            std::string statusString = selected->printStatus();
            auto status = selected->getStatus();

            ImGui::Value("Id", id);

            char buffer[256];
            strcpy(buffer, name.c_str()); // copy name to buffer
            if (ImGui::InputText("Name", buffer, 256, ImGuiInputTextFlags_EnterReturnsTrue))
            {
                selected-> name = std::string(buffer);
            }
            ImGui::Text("Current Status: %s", statusString.c_str());
            if (ImGui::CollapsingHeader("Status"))
            {
                if (ImGui::RadioButton("NOT_YET_STARTED", status == Status::NOT_YET_STARTED))
                {
                    status = Status::NOT_YET_STARTED;
                    selected->setStatus(status);
                }
                if (ImGui::RadioButton("WORK_IN_PROGRESS", status == Status::WORK_IN_PROGRESS))
                {
                    status = Status::WORK_IN_PROGRESS;
                    selected->setStatus(status);
                }
                if (ImGui::RadioButton("DONE", status == Status::DONE))
                {
                    status = Status::DONE;
                    selected->setStatus(status);
                }
                if (ImGui::RadioButton("DEFERRED", status == Status::DEFERRED))
                {
                    status = Status::DEFERRED;
                    selected->setStatus(status);
                }
                if (ImGui::RadioButton("NOT_GOING_TO_HAPPEN", status == Status::NOT_GOING_TO_HAPPEN))
                {
                    status = Status::NOT_GOING_TO_HAPPEN;
                    selected->setStatus(status);
                }
            }

            if (ImGui::SliderFloat("Importance", &importance, Task::MIN_IMPORTANCE, Task::MAX_IMPORTANCE))
            {
                selected-> importance = importance;
            }

            if (ImGui::SliderFloat("Urgency", &urgency, Task::MIN_URGENCY, Task::MAX_URGENCY))
            {
                selected-> urgency = urgency;
            }
            ImGui::Text("Due Date");
            if (ImGui::InputInt("Day", &dueDateDay))
            {
                selected->setDueDate({dueDateDay,dueDateMonth,dueDateYear});
            }
            if (ImGui::InputInt("Month", &dueDateMonth))
            {
                selected->setDueDate({dueDateDay,dueDateMonth,dueDateYear});
            }
            if (ImGui::InputInt("Year", &dueDateYear))
            {
                selected->setDueDate({dueDateDay,dueDateMonth,dueDateYear});
            }
            ImGui::Text("Duration");
            if (ImGui::InputInt("Hours", &durationHours))
            {
                selected->setDuration({durationHours,durationMinutes});
            }
            if (ImGui::InputInt("Minutes", &durationMinutes))
            {
                selected->setDuration({durationHours,durationMinutes});
            }


            ImGui::End(); // End "Task Details"
        }

        // *** ImGui Widget for Task Stack
        // ImGuiCond_Always forces these conditions
        ImGui::SetNextWindowSize(ImVec2(200, 600), ImGuiCond_Always);
        ImGui::SetNextWindowPos(ImVec2(600, 0), ImGuiCond_Always);
        ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
        ImGui::Begin("Task Stack", 0, ImGuiWindowFlags_NoResize);

        for (auto iter = tasklist.begin(); iter != tasklist.end(); ++iter)
        {
            auto name = iter->name;
            auto id = iter->getId();

            name += "##" + std::to_string(id);
            if (ImGui::Selectable(name.c_str(), iter == selected))
            {
                selected = iter;
            }
        }
        ImGui::End(); // End "Task Stack"


        // ************************************************************
        // RENDER CALLS
        // ************************************************************

        // Clear screen
        window.clear();

        // Draw Graph
        bool selectedValid = (selected != tasklist.end());
        grid.draw(window, tasklist, selectedValid? selected->getId() : 0);

        // Render ImGui widgets on top of everything else
        ImGui::SFML::Render(window);

        // Update the window
        window.display();
    }


    // ****************************************************************
    // APP SHUTDOWN
    // ****************************************************************

    // CJ: My understanding is ShutDown() does some clean up
    ImGui::SFML::Shutdown();

    return 0;
}
