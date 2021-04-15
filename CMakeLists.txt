# cmake_minimum_required(VERSION <specify CMake version here>)
project(SDIZO_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDIZO_Project ArrayList/ArrayList.cpp ArrayList/ArrayList.h main.cpp main.h DLinkedList/DLinkedList.cpp DLinkedList/DLinkedList.h DLinkedList/Node.cpp DLinkedList/Node.h BinaryHeap/BinaryHeap.cpp BinaryHeap/BinaryHeap.h "MainMenu/IOShell.cpp" "MainMenu/IOShell.h" MainMenu/MainMenu.cpp MainMenu/MainMenu.h BinarySearchTree/BinarySearchTree.cpp BinarySearchTree/BinarySearchTree.h BinarySearchTree/Node.cpp BinarySearchTree/Node.h)