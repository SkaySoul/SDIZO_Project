//
// Created by hellf on 05.03.2021.
//

#ifndef SDIZO_PROJECT_DLINKEDLIST_H
#define SDIZO_PROJECT_DLINKEDLIST_H


#include "Node.h"
#include <iostream>
using namespace std;

class DLinkedList {
private:


    unsigned long size;
    Node *head;
    Node *tail;
    void pushFront(int elem);
    void popFront();
    void popBack();
    void pushBack(int elem);
    void addToPos(unsigned long pos, int elem);
    void deleteFromAnyPos(unsigned long pos);


public:
    unsigned long getSize() const;
    void findElem(int elem);
//  int getElem(unsigned long pos);
    bool isEmpty() const;
    DLinkedList();
    DLinkedList(unsigned long arrSize, int *arr);
    ~DLinkedList();
    void addElem(unsigned long pos, int elem);
    void deleteElemOnPos(unsigned long pos);
    void show();
};


#endif //SDIZO_PROJECT_DLINKEDLIST_H

