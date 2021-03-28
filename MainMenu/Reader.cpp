//
// Created by hellf on 3/23/2021.
//

#include "Reader.h"
using namespace std;

Reader::Reader(String filename){
    file.open(filename, ios::in);
    trff();
    int arr[arraySize] = rff();
};

void Reader::trff(){
    if (!file) {
        cout << "No such file";
    }
    else{
        int array[100];
        char ch;
        int cnt = 0;
        String s = "";
        while(true){
            file>>ch;
            if(ch!=" "){
                s.push_back(ch);
            }
            else{
                int nm = s.stoi();
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
void Reader::rff(){
    if (!file) {
        cout << "No such file";
    }
    else{
        int array[100];
        char ch;
        int cnt = 0;
        String s = "";
        while(true){
            file>>ch;
            if(ch!=" "){
                s.push_back(ch);
            }
            else{
                int nm = s.stoi();
                array[cnt] = nm;
                s = "";
            }
            if (file.eof())
                break;
            cnt++;
        }
    }
    int newArr[arraySize];
    for(int i = 0; i<arraySize-1){
        newArr[i] = array[i];
    }

    return newArr;
}


Reader::~Reader() {
    my_file.close();
}


