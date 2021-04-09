//
// Created by hellf on 3/9/2021.
//
#include "../ArrayList/ArrayList.h"
#ifndef SDIZO_PROJECT_BINARYHEAP_H
#define SDIZO_PROJECT_BINARYHEAP_H


class BinaryHeap{

private:


    unsigned long size;
    ArrayList *arraylist;
public:
    void addElem(int elem);
    unsigned long getSize();
    BinaryHeap(unsigned long arrSize, int *arr);
    explicit BinaryHeap(unsigned long size);
    ~BinaryHeap();
    void heapify(unsigned long pos);
    void removeRoot();
    int getElem(int pos);
    bool findElem(unsigned long startPos, int elem);
};


#endif //SDIZO_PROJECT_BINARYHEAP_H
