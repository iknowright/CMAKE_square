cmake_minimum_required(VERSION 3.4)

project("To Do List")

enable_testing()

add_executable(toDo main.cc ToDo.cc)

add_test(toDoTest toDo)