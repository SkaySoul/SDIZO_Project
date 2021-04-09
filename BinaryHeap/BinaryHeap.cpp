//
// Created by hellf on 3/9/2021.
//
#include "BinaryHeap.h"
#include <iostream>

BinaryHeap::BinaryHeap(unsigned long size) {
    this->arraylist = new ArrayList(size);
    this->size = arraylist->getSize();
}

BinaryHeap::BinaryHeap(unsigned long arrSize, int *arr){
    this->arraylist = new ArrayList(0);
    this->size = 0;
    for(int i = 0; i<arrSize; i++){
        addElem(arr[i]);
    }
}

BinaryHeap::~BinaryHeap() {
 delete arraylist;
}

void BinaryHeap::addElem(int elem) {
    unsigned long i = size, parent = (i-1)/2;
    arraylist->addElem(elem);
    while(parent >= 0 && i > 0)  {
        if(arraylist->getElem(i) > arraylist->getElem(parent)) {
            int temp = arraylist->getElem(i);
            arraylist->setElem(arraylist->getElem(parent),i);
            arraylist->setElem(temp,parent);
        }
        i = parent;
        parent = (i-1)/2;
    }
    size++;
}

void BinaryHeap::heapify(unsigned long pos){
unsigned long lch = 2 * pos + 1;
unsigned long rch = 2 * pos + 2;
int temp;
    if(lch < size) {
        if(arraylist->getElem(pos) < arraylist->getElem(lch)) {
            temp = arraylist->getElem(pos);
            arraylist->setElem(arraylist->getElem(lch), pos);
            arraylist->setElem(temp,lch);
            heapify(lch);
        }
    }
    if(rch < size) {
        if(arraylist->getElem(pos) < arraylist->getElem(rch)) {
            temp = arraylist->getElem(pos);
            arraylist->setElem(arraylist->getElem(rch), pos);
            arraylist->setElem(temp,rch);
            heapify(rch);
        }
    }
}

unsigned long BinaryHeap::getSize() {
    return this->size;
}

bool BinaryHeap::findElem(unsigned long startPos, int elem) {

    unsigned long lch = 2*startPos+1;
    unsigned long rch = 2*startPos+1;
    if(arraylist->getElem(startPos) == elem){
        return true;
    }
    if(lch>arraylist->getSize()){
        return false;
    }
    bool isFounded = findElem(lch, elem);
    if (isFounded){
        return true;
    }
    if(rch>arraylist->getSize()){
        return false;
    }
    return findElem(rch, elem);
}

int BinaryHeap::getElem(int pos) {
    return arraylist->getElem(pos);
}

void BinaryHeap::removeRoot() {
    arraylist->setElem(arraylist->getElem(size-1),0);
    arraylist->deleteElemOnPos(size-1);
    size--;
    heapify(0);
}












