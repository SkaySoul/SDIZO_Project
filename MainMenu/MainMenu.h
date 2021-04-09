//
// Created by hellf on 3/28/2021.
//

#ifndef SDIZO_PROJECT_MAINMENU_H
#define SDIZO_PROJECT_MAINMENU_H
#include "Reader.h"
#include "../ArrayList/ArrayList.h"
#include <windows.h>
#include <iostream>
#include <iomanip>

class MainMenu {
private:
    string path;
public:
    Reader *reader;
    MainMenu();
    void start() const;
    static string initPath();
    static int chooser();
    static void showOperations();
    void workWithArraylist() const;
    void workWithDLinkedList() const;
    void workWithBinaryHeap() const;

    long long int read_QPC();

    void showTime();
};


#endif //SDIZO_PROJECT_MAINMENU_H
