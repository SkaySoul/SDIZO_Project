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
    Reader(string filename);
    ~Reader();
    void trff();
    int* rff();
    int arraySize;
    int* arr;
};


#endif //SDIZO_PROJECT_READER_H
