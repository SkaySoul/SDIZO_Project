//
// Created by hellf on 4/13/2021.
//


#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(unsigned long size, int *arr) {
    this->size = 0;
    this->root =nullptr;
    for(int i = 0; i<size-1; i++){
        addElem(arr[i]);
    }
}

BinarySearchTree::~BinarySearchTree(){
    for(unsigned long i = 0; i< size-1; i--){
        deleteElem(i);
    }
}

void BinarySearchTree::addElem(int elem) {
    if(size == 0){
        Node *node = new Node(nullptr, nullptr, nullptr, elem);
        root = node;
    }
    else adder(root, elem);
    size++;
}

void BinarySearchTree::adder(Node *temp, int elem){
    if (temp->lch == nullptr && temp->rch == nullptr){
        Node *newNode = new Node(temp, nullptr, nullptr, elem);
        if (temp->val < elem){
            temp->lch = newNode;
        }
        if(temp->val > elem){
            temp->rch = newNode;
        }
    }
    if(temp->lch == nullptr){
        if (temp->val > elem){
            Node *newNode = new Node(temp, nullptr, nullptr, elem);
            temp->lch = newNode;
        }
        else{
            adder(temp->rch, elem);
        }
    }
    if(temp->rch == nullptr){
        if (temp->val < elem){
            Node *newNode = new Node(temp, nullptr, nullptr, elem);
            temp->rch = newNode;
        }
        else{
            adder(temp->lch,elem);
        }
    }
    if(temp->val > elem){
        adder(temp->lch,elem);
    }
    if(temp->val < elem){
        adder(temp->rch,elem);
    }
}

void BinarySearchTree::findElem(int elem) {
    if(size == 0){
        cout<<"Tree is empty"<<endl;
    }
    else{
        Node *temp = finder(root, elem);
        if(temp != nullptr){
            cout<<"Element founded!"<<endl;
        }
        else cout<<"Element not founded!"<<endl;
    }
}

Node* BinarySearchTree::finder(Node *temp, int elem){
    if(temp->val == elem){
        return temp;
    }
    else if(temp->val > elem){
        if(temp->lch == nullptr){
            return nullptr;
        }
        finder(temp->lch, elem);
    }
    else{
        if(temp->rch == nullptr){
            return nullptr;
        }
        finder(temp->rch, elem);
    }
}

void BinarySearchTree::deleteElem(int elem) {
    if(size == 0){
        cout<<"Tree is empty!"<<endl;
        return;
    }
    else{
        Node *temp = finder(root, elem);
        if(temp != nullptr){
            //deleter
        }
        else cout<<"Element not founded"<<endl;
    }
}
