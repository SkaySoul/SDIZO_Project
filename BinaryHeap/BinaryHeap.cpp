//
// Created by hellf on 3/9/2021.
//
#include "BinaryHeap.h"
#include <iostream>

BinaryHeap::BinaryHeap(unsigned long size) {
    this->arraylist = new ArrayList(size);
    this->size = arraylist->getSize();
}

BinaryHeap::~BinaryHeap() {
 delete arraylist;
}

void BinaryHeap::add(int elem) {
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

void BinaryHeap::heapify(unsigned long i){
unsigned long lch = 2*i+1;
unsigned long rch = 2*i+2;
int temp;
    if(lch < size) {
        if(arraylist->getElem(i) < arraylist->getElem(lch)) {
            temp = arraylist->getElem(i);
            arraylist->setElem(arraylist->getElem(lch),i);
            arraylist->setElem(temp,lch);
            heapify(lch);
        }
    }
    if(rch < size) {
        if(arraylist->getElem(i) < arraylist->getElem(rch)) {
            temp = arraylist->getElem(i);
            arraylist->setElem(arraylist->getElem(rch),i);
            arraylist->setElem(temp,rch);
            heapify(rch);
        }
    }
}

unsigned long BinaryHeap::getSize(){
    return size;
}

int BinaryHeap::findElem(int elem) {
    bool isFounded;
    for(int i = 0; i<size; i++){
        if(elem == arraylist->getElem(i)){
            isFounded = true;
            return i;
        }
    }
    std::cout<<"Element is not founded"<<std::endl;
    return 1;
}

int BinaryHeap::findElemOnPos(int pos) {
    return arraylist->getElem(pos);
}

void BinaryHeap::removeRoot() {
    arraylist->setElem(arraylist->getElem(size-1),0);
    arraylist->deleteElemOnPos(size-1);
    size--;
    heapify(0);
}












