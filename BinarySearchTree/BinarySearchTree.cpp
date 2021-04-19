//
// Created by hellf on 4/13/2021.
//


#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(unsigned long size, int *arr) {
    this->size = 0;
    this->root =nullptr;
    for(int i = 0; i<size; i++){
        addElem(arr[i]);
    }
}

BinarySearchTree::~BinarySearchTree(){
    for(unsigned long i = 0; i< size-1; i--){
        deleter(root);
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
        return;
    }
    if(temp->lch == nullptr){
        if (temp->val > elem){
            Node *newNode = new Node(temp, nullptr, nullptr, elem);
            temp->lch = newNode;
            return;
        }
        else{
            adder(temp->rch, elem);
        }
    }
    if(temp->rch == nullptr){
        if (temp->val < elem){
            Node *newNode = new Node(temp, nullptr, nullptr, elem);
            temp->rch = newNode;
            return;
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
    return nullptr;
}

void BinarySearchTree::deleteElem(int elem) {
    if(size == 0){
        cout<<"Tree is empty!"<<endl;
        return;
    }
    else{
        Node *temp = finder(root, elem);
        if(temp != nullptr){
            deleter(temp);
        }
    }
}

void BinarySearchTree::deleter(Node *deletedNode){
    if(deletedNode->lch!=nullptr && deletedNode->rch!=nullptr) {
        Node* maxLeftTreeNode = getMaxNode(deletedNode->lch);
        deletedNode->val = maxLeftTreeNode->val;
        deleter(maxLeftTreeNode);
        return;
    }
    else
    {
        if(deletedNode->lch!=nullptr) {
            if(deletedNode==root) {
                Node* newRoot = deletedNode->lch;
                free(root);
                root = newRoot;
                return;
            }
            else
            {
                if(deletedNode == deletedNode->parent->lch) {
                    deletedNode->parent->lch = deletedNode->lch;
                }
                else deletedNode->parent->rch = deletedNode->lch;
            }
        }
        else
        {
            if(deletedNode->rch!=nullptr) {
                if(deletedNode==root) {
                    Node* newRoot = deletedNode->rch;
                    free(root);
                    root = newRoot;
                    return;
                }
                else
                {
                    if(deletedNode == deletedNode->parent->rch) {
                        deletedNode->parent->rch = deletedNode->rch;
                    }
                    else deletedNode->parent->lch = deletedNode->rch;
                }
            }
            else
            {
                if(deletedNode==root) {
                    free(root);
                    root = nullptr;
                    return;
                }
                else {
                    if(deletedNode == deletedNode->parent->lch) {
                        deletedNode->parent->lch = nullptr;
                    }
                    else
                    {
                        deletedNode->parent->rch = nullptr;
                    }
                }
            }
        }
    }
    free(deletedNode);
}

Node *BinarySearchTree::getMaxNode(Node *start) {
    while(start->rch!= nullptr){
        start = start->rch;
    }
    return start;
}
