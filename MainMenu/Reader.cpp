//
// Created by hellf on 3/23/2021.
//

#include "Reader.h"
#include <iostream>
using namespace std;

Reader::Reader(string filename){
    file.open(filename, ios::in);
    trff();
    int *arr = new int[arraySize];
    arr = rff();
};

void Reader::trff(){
    int array[100];
    if (!file) {
        cout << "No such file";
    }
    else{

        char ch;
        int cnt = 0;
        string s = "";
        while(true){
            file>>ch;
            if(ch != ' '){
                s.push_back(ch);
            }
            else{
                int nm = stoi(s);
                array[cnt] = nm;
                s = "";
            }
            if (file.eof())
                break;
        cnt++;
        }
    }
    int size = 1;
    while (array[size]!=0){
        size++;
    }
    int arraySize = size;
}

int* Reader::rff(){
    int *array = new int[100]  ;
    if (!file) {
        cout << "No such file";
    }
    else{

        char ch;
        int cnt = 0;
        string s = "";
        while(true){
            file>>ch;
            if(ch!=' '){
                s.push_back(ch);
            }
            else{
                int nm = stoi(s);
                array[cnt] = nm;
                s = "";
            }
            if (file.eof())
                break;
            cnt++;
        }
    }
    int size = arraySize;
    int newArr[size];
    for(int i = 0; i<arraySize-1; i++){
        newArr[i] = array[i];
    }

    return newArr;
}


Reader::~Reader() {
    file.close();
}


