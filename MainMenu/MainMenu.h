//
// Created by hellf on 3/28/2021.
//

#ifndef SDIZO_PROJECT_MAINMENU_H
#define SDIZO_PROJECT_MAINMENU_H
#include "IOShell.h"
#include "../ArrayList/ArrayList.h"
#include "../DLinkedList/DLinkedList.h"
#include "../BinaryHeap/BinaryHeap.h"
#include "../BinarySearchTree/BinarySearchTree.h"
#include <utility>
#include <windows.h>
#include <iostream>
#include <iomanip>

class MainMenu {
private:
    static int chooser();
    static void showOperations();
    void workWithArraylist() const;
    void workWithDLinkedList() const;
    void workWithBinaryHeap() const;
    static long long int read_QPC();
public:
    IOShell *reader;
    MainMenu();
    void start() const;

    void workWithBST() const;
};


#endif //SDIZO_PROJECT_MAINMENU_H
