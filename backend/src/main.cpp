//
// Created by bryant on 4/16/19.
//

#include <iostream>
using std::cout, std::endl;

#include "../include/task.hpp"

int main(){
    Task task1;
    cout << task1.get_name() << " " << task1.get_id() << endl;

    Task task2;
    task2.set_name("Do the fisrt task");
    cout << task2.get_name() << " " << task2.get_id() << endl;

    return 0;
}