//
// Created by hellf on 04.03.2021.
//

#ifndef SDIZO_PROJECT_ARRAYLIST_H
#define SDIZO_PROJECT_ARRAYLIST_H


class ArrayList{
private:
    unsigned long size;
    int *ptr;
    void addToAnyPos(int elem, unsigned long pos);
    void addToFirstPos(int elem);
    void addToLastPos(int elem);
    void deleteFromFirstPos();
    void deleteFromAnyPos(unsigned long pos);
    void deleteFromLastPos();
public:
    ArrayList(unsigned long size, int array[]);
    explicit ArrayList(unsigned long size);
    ~ArrayList();
    void addElem(int elem, unsigned long pos);
    void addElem(int elem);
    void setElem(int elem, unsigned long pos);
    int getElem(unsigned long pos);
    void deleteElemOnPos(unsigned long pos);
    void deleteElem(int elem);
    unsigned long findElem(int elem);
    unsigned long getSize();
    bool isEmpty();
};

#endif //SDIZO_PROJECT_ARRAYLIST_H