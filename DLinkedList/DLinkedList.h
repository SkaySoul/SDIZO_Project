//
// Created by hellf on 05.03.2021.
//

#ifndef SDIZO_PROJECT_DLINKEDLIST_H
#define SDIZO_PROJECT_DLINKEDLIST_H


#include "Node.h"

class DLinkedList {
private:



public:
    unsigned long size;
    Node *head, *tail;

    void deleteDLinkedList(DLinkedList **list);

    };


#endif //SDIZO_PROJECT_DLINKEDLIST_H

