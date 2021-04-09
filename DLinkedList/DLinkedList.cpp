//
// Created by hellf on 05.03.2021.
//

#include "DLinkedList.h"
#include <iostream>


DLinkedList::DLinkedList() {
    this->size = 0;
    this->head = this->tail = nullptr;
}
DLinkedList::DLinkedList(unsigned long arrSize, int *arr) {
    this->size = 0;
    this->head = this->tail = nullptr;
    for (int i = 0; i<arrSize; i++){
        if (i == 0){

        }
        pushBack(arr[i]);

    }
}

DLinkedList::~DLinkedList() {
    while(size!=0){
     popFront();
     size--;
    }
}

void DLinkedList::pushFront(int elem) {
    Node *temp = new Node(nullptr, head, elem);
    if (head != nullptr) {
        head->prev = temp;
    }
    else{
        tail = temp;
    }
    head = temp;
    size++;
}

void DLinkedList::popFront() {
    if (head == nullptr) {
        std::cout<<"This list already empty!"<<std::endl;
        return;
    }
    if(head == tail){
        tail = nullptr;
        delete head;
        head = nullptr;
        size--;
        return;
    }
    Node *temp = head->next;
    head->next->prev = nullptr;
    delete head;
    head = temp;
    size--;
}

void DLinkedList::popBack() {
    if (tail == nullptr) {
        std::cout<<"This list already empty!"<<std::endl;
        return;
    }
    if(head == tail){
        head = nullptr;
        delete tail;
        return;
    }
    Node *temp = tail->prev;
    tail->prev->next = nullptr;
    delete tail;
    tail = temp;
    size--;
}

void DLinkedList::pushBack(int elem) {
    Node *temp = new Node(tail, nullptr, elem);
    if (tail != nullptr) {
        tail->next = temp;
    }
    else{
        head = temp;
    }
    tail = temp;
    size++;
}

unsigned long DLinkedList::findElem(int elem) {
    if (isEmpty()){
        std::cout<<"This list is empty!"<<std::endl;
    }
    Node *temp = head;
    for (unsigned long i = 0; i<size-1;i++){
        if(temp->value == elem){
            return i+1;
        }
        else {
            temp = temp->next;
            if (temp == nullptr){
                std::cout<<"Element is not founded"<<std::endl;

            }
        }
    }
    return -1;
}

int DLinkedList::getElem(unsigned long pos) {
    if (pos>size-1){
        std::cout<<"Position is too big for list, this list contain only "<< getSize() <<" elements"<<std::endl;

    }
    if (pos == 0){
        return head->value;
    }
    else if (pos == size-1){
        return tail->value;
    }
    else
    {
        if (pos < size % 2) {
            Node *temp = head;
            for (unsigned long i = 0; i < pos; i++) {
                temp = temp->next;
            }
            return temp->value;
        }
        if (pos > size % 2) {
            Node *temp = tail;
            for (unsigned long i = size - 1; i > pos; i--) {
                temp = temp->prev;
            }
            return temp->value;
        }
    }
    return 0;
}


void DLinkedList::addToPos(unsigned long pos, int elem){
    if (pos>size){
        std::cout<<"Error! List contain only "<< size<< " elements"<< std::endl;
        return;
    }
    Node *temp = head;
    for (unsigned long i = 0; i<pos-1; i++){
        temp = temp->next;
    }
    Node *newNode = new Node(temp,temp->next,elem);
    temp->next->prev = newNode;
    temp->next = newNode;
    size++;
}

void DLinkedList::addElem(unsigned long pos, int elem) {
    if (pos == 0){
        pushFront(elem);
    }
    else if (pos == size){
        pushBack(elem);
    }
    else{
        addToPos(pos,elem);
    }
}

void DLinkedList::deleteFromAnyPos(unsigned long pos){
    Node *temp = head;
    for (unsigned long i = 0; i<pos; i++){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size--;
}

void DLinkedList::deleteElemOnPos(unsigned long pos) {
    if (pos>size-1){
        std::cout<<"Error! List contain only "<< size << " elements"<< std::endl;
        return;
    }
    if (pos == 0){
        popFront();
        return;
    }
    if (pos == size-1){
        popBack();
        return;
    }
    else{
        deleteFromAnyPos(pos);
        return;
    }
}

void DLinkedList::deleteElem(int elem) {
    unsigned long pos = findElem(elem);
    deleteElemOnPos(pos);
}

unsigned long DLinkedList::getSize() {
    return size;
}

bool DLinkedList::isEmpty(){
    if (size == 0){
        return true;
    }
    return false;
}

void DLinkedList::show(){
    if(isEmpty()){
    std::cout<<"This list is empty!"<<std::endl;
        return;
    }
    else{
        Node *temp = head;
        for (int i = 0; i<size; i++){
            std::cout<<temp->value;
            temp= temp->next;
            if (i<size-1){
                std::cout<<", ";
            }
            else std::cout<<std::endl;

        }


    }

}


