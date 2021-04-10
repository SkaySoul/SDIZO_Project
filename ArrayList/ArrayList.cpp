#include <iostream>
#include "ArrayList.h"


ArrayList::ArrayList(unsigned long size, const int *def_array){
    this->size = size;
    this->arr = (int*)calloc(size, sizeof(int));
    for(unsigned long i=0;i<size;i++){
        arr[i] = def_array[i];
    }
}

ArrayList::ArrayList(unsigned long size){
    this->size = size;
    this->arr = (int*)calloc(size, sizeof(int));
}

ArrayList::~ArrayList(){
    delete arr;
}

void ArrayList::addToFirstPos(int elem) {
    int temp = arr[size - 1];
    for(unsigned long i = size-1; i>0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = elem;
    int *temp_ptr = (int*)calloc(size + 1, sizeof(int));
    memcpy(temp_ptr, arr, (size + 1) * sizeof(int));
    size++;
    delete[] arr;
    temp_ptr[size-1] = temp;
    arr = temp_ptr;

}

void ArrayList::addToAnyPos(int elem, unsigned long pos) {
    int temp = arr[size - 1];
    for(unsigned long i = size-1; i>pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = elem;
    int *temp_ptr = (int*)calloc(size + 1, sizeof(int));
    size++;
    memcpy(temp_ptr, arr, size * sizeof(int));
    delete[] arr;
    temp_ptr[size-1] = temp;
    arr = temp_ptr;

}

void ArrayList::addToLastPos(int elem) {
    int *temp_ptr = (int*)calloc(size + 1, sizeof(int));
    memcpy(temp_ptr, arr, size * sizeof(int));
    delete[] arr;
    size++;
    temp_ptr[size-1] = elem;
    arr = temp_ptr;
}

void ArrayList::addElem(int elem, unsigned long pos){
    if(pos>size+1){
        return;
    }
    if(pos == 0){
        addToFirstPos(elem);
    }
    else if(pos == size){
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
    return arr[pos];
}

void ArrayList::findElem(int elem) {
    for(unsigned long i = 0;i<size-1;i++){
        if(elem == arr[i]){
            cout<<"Element is on this position: "<<arr[i]<<endl;
            break;
        }
        if(i == size-2){
            cout<<"Element is not founded"<<endl;
        }
    }
}

void ArrayList::setElem(int elem, unsigned long pos) {
    arr[pos] = elem;
}

unsigned long ArrayList::getSize() const{
    return size;
}

void ArrayList::deleteFromFirstPos() {
    delete &arr[0];
    for(unsigned long i = 0; i<size-1; i++){
        arr[i] = arr[i + 1];
    }
    int *temp_ptr = (int*)calloc(size-1, sizeof(int));
    size--;
    memcpy(temp_ptr, arr, size * sizeof(int));
    delete[] arr;
    arr = temp_ptr;
}

void ArrayList::deleteFromAnyPos(unsigned long pos) {
    delete &arr[pos];
    for(unsigned long i = pos; i<size-1; i++){
        arr[i] = arr[i + 1];
    }
    int *temp_ptr = (int*)calloc(size-1, sizeof(int));
    size--;
    memcpy(temp_ptr, arr, size * sizeof(int));
    delete[] arr;
    arr = temp_ptr;
}

void ArrayList::deleteFromLastPos() {
    delete &arr[size - 1];
    int *temp_ptr = (int*)calloc(size-1, sizeof(int));
    size--;
    memcpy(temp_ptr, arr, size * sizeof(int));
    delete[] arr;
    arr = temp_ptr;
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

[[maybe_unused]] bool ArrayList::isEmpty() {
    for (int i = 0;i<size-1;i++){
        if (arr[i] != 0){
            return true;
        }
    }
    return false;
}

