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
        cout<<"This list already empty!"<<endl;
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
        cout<<"This list already empty!"<<endl;
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

void DLinkedList::findElem(int elem) {
    if (isEmpty()){
        cout<<"This list is empty!"<<endl;
    }
    Node *temp = head;
    for (unsigned long i = 0; i<size-1;i++){
        if(temp->value == elem){
            cout<<"Element is on "<<i+1<<" position";
            return;
        }
        else {
            temp = temp->next;
            if (temp == nullptr){
                cout<<"Element is not founded"<<endl;
                return;
            }
        }
    }
}

//int DLinkedList::getElem(unsigned long pos) {
//    if (pos>size-1){
//        cout<<"Position is too big for list, this list contain only "<< getSize() <<" elements"<<endl;
//
//    }
//    if (pos == 0){
//        return head->value;
//    }
//    else if (pos == size-1){
//        return tail->value;
//    }
//    else
//    {
//        if (pos < size % 2) {
//            Node *temp = head;
//            for (unsigned long i = 0; i < pos; i++) {
//                temp = temp->next;
//            }
//            return temp->value;
//        }
//        if (pos > size % 2) {
//            Node *temp = tail;
//            for (unsigned long i = size - 1; i > pos; i--) {
//                temp = temp->prev;
//            }
//            return temp->value;
//        }
//    }
//    return 0;
//}


void DLinkedList::addToPos(unsigned long pos, int elem){
    if (pos>size){
        cout<<"Error! List contain only "<< size<< " elements"<<endl;
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
        cout<<"Error! List contain only "<< size << " elements"<<endl;
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


[[maybe_unused]] unsigned long DLinkedList::getSize() const{
    return size;
}

bool DLinkedList::isEmpty() const{
    if (size == 0){
        return true;
    }
    return false;
}

void DLinkedList::show(){
    if(isEmpty()){
    cout<<"This list is empty!"<<endl;
        return;
    }
    else{
        Node *temp = head;
        for (int i = 0; i<getSize(); i++){
            std::cout<<temp->value;
            temp= temp->next;
            if (i<size-1){
                cout<<", ";
            }
            else cout<<endl;

        }
    }
}


