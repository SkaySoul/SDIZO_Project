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
    [[nodiscard]] unsigned long getSize() const;
    BinaryHeap(unsigned long arrSize, int *arr);
    ~BinaryHeap();
    void heapify(unsigned long pos);
    void removeRoot();
    int getElem(int pos);
    bool findElem(unsigned long startPos, int elem);
    void findElem(int elem);
};
#endif //SDIZO_PROJECT_BINARYHEAP_H
