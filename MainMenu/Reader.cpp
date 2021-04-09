
//Created by hellf on 3/23/2021.


#include "Reader.h"
#include <iostream>
#include <string>
using namespace std;

Reader::Reader(string path){
    file.open(path, ios::in);
    this->arraySize = getSize();
    this->arr = new int[arraySize];
    readFromFile();
}


void Reader::readFromFile(){
    int val;
    if(file.is_open()){
            for(int i = 0; i < arraySize; i++)
            {
                file >> val;
                if(file.fail())
                {
                    cout << "File error - READ DATA" << endl;
                    break;
                }
                else
                    arr[i] = val;
            }
    }
    else{
        cout << "File error - OPEN" << endl;
        return;
    }
}

unsigned long Reader::getSize(){
    unsigned long size = 0;
    if(file.is_open()){
        if(file.fail()){
            cout << "File error - READ SIZE" << endl;
            return -1;
        }
        else
            file >> size;
    }
    else{
        cout << "File error - OPEN" << endl;
        return -1;
    }

    return size;
}

Reader::~Reader() {
    delete arr;
    file.close();
}


