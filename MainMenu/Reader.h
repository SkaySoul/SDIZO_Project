//
// Created by hellf on 3/23/2021.
//

#ifndef SDIZO_PROJECT_READER_H
#define SDIZO_PROJECT_READER_H
#include <fstream>
#include<iostream>
using namespace std;
class Reader {
private:
    fstream file;
public:
    explicit Reader(string path);
    ~Reader();
    void readFromFile();
    unsigned long arraySize;
    int *arr;
    unsigned long getSize();
};


#endif //SDIZO_PROJECT_READER_H
