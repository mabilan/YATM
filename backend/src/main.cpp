//
// Created by bryant on 4/16/19.
//

#include <iostream>
using std::cout, std::endl;

#include "../include/task.hpp"

int main(){
    Task task1;
    cout << task1.getName() << " " << task1.getId() << endl;

    Task task2;
    task2.setName("Do the fisrt task");
    cout << task2.getName() << " " << task2.getId() << endl;

    return 0;
}