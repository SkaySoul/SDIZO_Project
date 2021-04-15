//
// Created by hellf on 4/13/2021.
//

#ifndef SDIZO_PROJECT_BINARYSEARCHTREE_H
#define SDIZO_PROJECT_BINARYSEARCHTREE_H


#include "Node.h"
#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    Node *root;
public:
    ~BinarySearchTree();
    void addElem(int elem);
    void deleteElem(int elem);
    void findElem(int elem);

    void adder(Node *temp, int elem);
    Node *finder(Node *temp, int elem);

    BinarySearchTree(unsigned long size, int *arr);

    unsigned long size;
};


#endif //SDIZO_PROJECT_BINARYSEARCHTREE_H
