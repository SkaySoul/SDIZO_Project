
//Created by hellf on 3/23/2021.


#include "IOShell.h"
#include <iostream>
#include <string>
using namespace std;

IOShell::IOShell(){
    this->path = initPath();
    rewriter();
    file.open(path, ios::in);
    this->arraySize = getSize();
    this->arr = new int[arraySize];
    readFromFile();
}

void IOShell::rewriter() const{
    bool selected =false;
    cout<<"Do you want randomize and rewrite the main data file?(y/n)"<<endl;
    while (!selected){
        char answer;
        cin>>answer;
        switch(answer){
            case 'y':{
                cout<<"Choose a quantity of numbers on the array"<<endl;
                int qtt;
                cin>>qtt;
                randomizeWriter(qtt);
                selected = true;
                break;
            }
            case 'n':{
                selected = true;
                break;
            }
            default:{
                cout<<"Incorrect answer, you need write 'y' or 'n'!"<<endl;
                break;
            }
        }
    }
}

void IOShell::readFromFile(){

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

unsigned long IOShell::getSize(){
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

IOShell::~IOShell() {
    delete arr;
    file.close();
}

void IOShell::randomizeWriter(int qtt) const {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    ofstream out;
    out.open(path);
    if (out.is_open()) {
        out<<qtt<<" ";
        for (int i = 0; i < qtt+1; i++) {
            int val = dist(gen);
            out<<val<<" ";
        }
    }
    out.close();
    cout<<"Rewriting was successful"<<endl;
}

string IOShell::initPath(){
    string temp;
    cout<<"Please insert file path..."<<endl;
    cin>>temp;
    return temp;
}