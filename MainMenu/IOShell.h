//
// Created by hellf on 3/23/2021.
//

#ifndef SDIZO_PROJECT_IOSHELL_H
#define SDIZO_PROJECT_IOSHELL_H
#include <fstream>
#include<iostream>
#include <random>

using namespace std;
class IOShell {
private:
    fstream file;
    string path;
public:
    explicit IOShell();
    ~IOShell();
    void readFromFile();
    unsigned long arraySize;
    int *arr;
    unsigned long getSize();
    void randomizeWriter(int qtt) const;
    static string initPath();
    void rewriter() const;
};


#endif //SDIZO_PROJECT_IOSHELL_H
