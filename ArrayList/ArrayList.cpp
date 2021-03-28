#include <iostream>
#include "ArrayList.h"


ArrayList::ArrayList(unsigned long size,  int array[]){
    this->size = size;
    this->ptr = (int*)calloc(size, sizeof(int));
    for(unsigned long i=0;i<size;i++){
        ptr[i] = array[i];
    }
}

ArrayList::ArrayList(unsigned long size){
    this->size = size;
    this->ptr = (int*)calloc(size, sizeof(int));
}

ArrayList::~ArrayList(){
    delete ptr;
}

void ArrayList::addToFirstPos(int elem) {
    int temp = ptr[size-1];
    for(unsigned long i = size-1; i>0; i--){
       ptr[i] = ptr[i-1];
    }
    ptr[0] = elem;
    int *temp_ptr = (int*)calloc(size + 1, sizeof(int));
    memcpy(temp_ptr,ptr,(size+1)*sizeof(int));
    size++;
    delete[] ptr;
    temp_ptr[size-1] = temp;
    ptr = temp_ptr;

}

void ArrayList::addToAnyPos(int elem, unsigned long pos) {
    int temp = ptr[size-1];
    for(unsigned long i = size-1; i>pos; i--){
        ptr[i] = ptr[i-1];
    }
    ptr[pos] = elem;
    int *temp_ptr = (int*)calloc(size + 1, sizeof(int));
    size++;
    memcpy(temp_ptr,ptr,size*sizeof(int));
    delete[] ptr;
    temp_ptr[size-1] = temp;
    ptr = temp_ptr;

}

void ArrayList::addToLastPos(int elem) {
    int *temp_ptr = (int*)calloc(size + 1, sizeof(int));
    memcpy(temp_ptr,ptr,size*sizeof(int));
    delete[] ptr;
    size++;
    temp_ptr[size-1] = elem;
    ptr = temp_ptr;
}

void ArrayList::addElem(int elem, unsigned long pos){
    if(pos == 0){
        addToFirstPos(elem);
    }
    else if(pos == size-1){
        addToLastPos(elem);
    }
    else{
        addToAnyPos(elem,pos);
    }
}
void ArrayList::addElem(int elem){
        addToLastPos(elem);
}

int ArrayList::getElem(unsigned long pos){
    return ptr[pos];
}

unsigned long ArrayList::findElem(int elem) {
    unsigned long temp;
    bool is_found = false;
    for(unsigned long i = 0;i<size-1;i++){
        if(elem == ptr[i]){
            temp = i;
            is_found = true;
            break;
        }
    }
    if(!is_found){
        std::cout<<"Element is not founded";
        return 0;
    }
    return temp;
}

void ArrayList::setElem(int elem, unsigned long pos) {
    ptr[pos] = elem;
}

unsigned long ArrayList::getSize(){
    return size;
};

void ArrayList::deleteFromFirstPos() {
    delete &ptr[0];
    for(unsigned long i = 0; i<size-1; i++){
        ptr[i] = ptr[i+1];
    }
    int *temp_ptr = (int*)calloc(size-1, sizeof(int));
    size--;
    memcpy(temp_ptr,ptr,size*sizeof(int));
    delete[] ptr;
    ptr = temp_ptr;
}

void ArrayList::deleteFromAnyPos(unsigned long pos) {
    delete &ptr[pos];
    for(unsigned long i = pos; i<size-1; i++){
        ptr[i] = ptr[i+1];
    }
    int *temp_ptr = (int*)calloc(size-1, sizeof(int));
    size--;
    memcpy(temp_ptr,ptr,size*sizeof(int));
    delete[] ptr;
    ptr = temp_ptr;
}

void ArrayList::deleteFromLastPos() {
    delete &ptr[size-1];
    int *temp_ptr = (int*)calloc(size-1, sizeof(int));
    size--;
    memcpy(temp_ptr,ptr,size*sizeof(int));
    delete[] ptr;
    ptr = temp_ptr;
}

void ArrayList::deleteElem(int elem) {
    int pos = findElem(elem);
    deleteElemOnPos(pos);
}

void ArrayList::deleteElemOnPos(unsigned long pos) {
    if(pos == 0){
        deleteFromFirstPos();
    }
    else if (pos == size-1){
        deleteFromLastPos();
    }
    else{
        deleteFromAnyPos(pos);
    }
}

bool ArrayList::isEmpty() {
    for (int i = 0;i<size-1;i++){
        if (ptr[i] != 0){
            return true;
        }
    }
    return false;
}