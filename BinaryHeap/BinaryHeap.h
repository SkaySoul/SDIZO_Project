//
// Created by hellf on 3/9/2021.
//
#include "../ArrayList/ArrayList.h"
#ifndef SDIZO_PROJECT_BINARYHEAP_H
#define SDIZO_PROJECT_BINARYHEAP_H


class BinaryHeap {

private:
    unsigned long size;
    ArrayList *arraylist;
public:
    explicit BinaryHeap(unsigned long size);
    ~BinaryHeap();
    void add(int elem);
    void heapify(unsigned long i);
    void removeRoot();
    int findElem(int elem);
    int findElemOnPos(int pos);
    unsigned long getSize();
};


#endif //SDIZO_PROJECT_BINARYHEAP_H
