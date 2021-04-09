//
// Created by hellf on 04.03.2021.
//

#ifndef SDIZO_PROJECT_ARRAYLIST_H
#define SDIZO_PROJECT_ARRAYLIST_H
#include <fstream>


using namespace std;

class ArrayList{
private:
    unsigned long size;
    int *arr;
    void addToAnyPos(int elem, unsigned long pos);
    void addToFirstPos(int elem);
    void addToLastPos(int elem);
    void deleteFromFirstPos();
    void deleteFromAnyPos(unsigned long pos);
    void deleteFromLastPos();

public:
    void addElem(int elem);
    void deleteElem(int elem);
    unsigned long findElem(int elem);
    int getElem(unsigned long pos);
    unsigned long getSize();
    bool isEmpty();

    ArrayList(unsigned long size, const int *array);
    explicit ArrayList(unsigned long size);
    ~ArrayList();
    void addElem(int elem, unsigned long pos);
    void setElem(int elem, unsigned long pos);
    void deleteElemOnPos(unsigned long pos);

};

#endif //SDIZO_PROJECT_ARRAYLIST_H