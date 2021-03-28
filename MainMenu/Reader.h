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
    int arraySize;
    int arr[];
public:
    Reader(String filename);
    ~Reader();
    void trff();
    int[] rff();

};


#endif //SDIZO_PROJECT_READER_H
