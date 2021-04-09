//
// Created by hellf on 3/28/2021.
//

#include "MainMenu.h"
#include "../DLinkedList/DLinkedList.h"
#include "../BinaryHeap/BinaryHeap.h"
#include <iostream>
#include <utility>
using namespace std;


MainMenu::MainMenu(){
    this->path = initPath();
    this->reader = new Reader(path);
}
void MainMenu::start() const{
    bool isWorking = true;
    while (isWorking){
        cout<<"Insert number: "<<endl<<"1. Create Arraylist"<<endl<<"2. Create Doubly Linked List"<<endl<<"3. Create BinaryHeap"<<endl<<"4. Create Binary Search Tree"<<endl<<"5. Exit"<<endl;
        int num = 0;
        string str;
        cin>>num;
        switch(num) {
            case 1: {
                cout<<"Arraylist created"<<endl;
                workWithArraylist();
                break;
            }

            case 2: {
                cout<<"DoublyLinkedList created"<<endl;
                workWithDLinkedList();
                break;
            }

            case 3: {
                cout<<"BinaryHeap created"<<endl;
                workWithBinaryHeap();
                break;
            }

            case 4: {
                cout<<"Binary Search Tree created"<<endl;
                break;
            }

            case 5: {
                isWorking = false;
                break;
            }

            default:{
                cout<<"Incorrect number selected"<<endl;
                break;
            }
        }
    }

}


void MainMenu::workWithArraylist() const{
    ArrayList *arrayList = new ArrayList(reader->arraySize, reader->arr);
    bool isWorking = true;
    while(isWorking) {
        showOperations();
        int num = chooser();
        switch (num) {
            case 0: {
                isWorking = false;
                break;
            }
            case 1: {
                cout << "Write an element: " << endl;
                int elem = chooser();
                cout << "Write position: " << endl;
                int pos = chooser();
                arrayList->addElem(elem, pos);
                cout << "Element added!" << endl;
                break;

            }
            case 2: {
                cout << "Write an position: " << endl;
                int pos = chooser();
                if(pos>arrayList->getSize()){
                    cout<<"Incorrect position, array is lower than your written number"<<endl;
                }
                else{
                    arrayList->deleteElemOnPos(pos+1);
                }
                break;
            }
            case 3: {
                cout << "Write an element: " << endl;
                int elem = chooser();
                unsigned long pos = arrayList->findElem(elem);
                if(pos!=-1){
                    cout<<"This element is on position: " << pos << endl;
                }
                break;
            }
            case 4: {
                for(int i = 0; i<arrayList->getSize(); i++){
                    cout<<arrayList->getElem(i);
                    if (i == arrayList->getSize()-1){
                        cout<<endl;
                    }
                    else
                        cout<<", ";
                }
                break;
            }
            default:{
                cout<<"Incorrect number!"<<endl;
                break;
            }
        }
    }
}


void MainMenu::workWithDLinkedList() const{
    DLinkedList *dLinkedList = new DLinkedList(reader->arraySize, reader->arr);
    bool isWorking = true;
    while(isWorking) {
        showOperations();
        int num = chooser();
        switch (num) {
            case 0: {
                isWorking = false;
                break;
            }
            case 1: {
                cout << "Write an element: " << endl;
                int elem = chooser();
                cout << "Write position: " << endl;
                int pos = chooser();
                dLinkedList->addElem(pos, elem);
                cout << "Element added!" << endl;
                break;

            }
            case 2: {
                cout << "Write an position: " << endl;
                int pos = chooser();
                dLinkedList->deleteElemOnPos(pos);
                break;
            }
            case 3: {
                cout << "Write an element: " << endl;
                int elem = chooser();
                unsigned long pos = dLinkedList->findElem(elem);
                if(pos!=-1){
                    cout<<"This element is on position: " << pos << endl;
                }
                break;
            }
            case 4: {
                dLinkedList->show();
                break;
            }

            default:{
                cout<<"Incorrect number!"<<endl;
                break;
            }

        }
    }
}

void MainMenu::workWithBinaryHeap() const{
    BinaryHeap *heap = new BinaryHeap(reader->arraySize, reader->arr);
    bool isWorking = true;
    while(isWorking) {
        cout<<"0. Exit to main menu"<<endl<<"1. Add element to structure"<<endl<<"2. Delete root of heap"<<endl<<"3. Find element on structure"<<endl<<"4. Show structure like array"<<endl;
        int num = chooser();
        switch (num) {
            case 0: {
                isWorking = false;
                break;
            }
            case 1: {
                cout << "Write an element: " << endl;
                int elem = chooser();
                heap->addElem(elem);
                cout << "Element added!" << endl;
                break;

            }
            case 2: {
                heap->removeRoot();
                break;
            }
            case 3: {
                cout << "Write an element: " << endl;
                int elem = chooser();
                if(heap->findElem(0,elem)){
                    cout<<"Element is founded"<< endl;
                }
                else{
                    cout<<"Element is not founded"<< endl;
                }
                break;
            }
            case 4: {
                for(int i = 0; i<heap->getSize(); i++){
                    cout<<heap->getElem(i);
                    if(i<heap->getSize()-1){
                        cout<<", ";
                    }
                    else{
                        cout<<endl;
                    }
                }
                break;
            }

            default:{
                cout<<"Incorrect number!"<<endl;
                break;
            }

        }
    }
}


void MainMenu::showOperations(){
        cout<<"Please choose an operation "<<endl;
        cout<<"0. Exit to main menu"<<endl;
        cout<<"1. Add element to structure"<<endl;
        cout<<"2. Delete element from structure"<<endl;
        cout<<"3. Find element on structure"<<endl;
        cout<<"4. Show structure"<<endl;
}

int MainMenu::chooser(){
    int num;
    cin>>num;
    return num;
}


string MainMenu::initPath(){
    string temp;
    cout<<"Please insert file path..."<<endl;
    cin>>temp;
    return temp;
}

long long int MainMenu::read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void MainMenu::showTime(){
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();
    //some code
    elapsed = read_QPC() - start;
    cout << "Time [ms] = " << setprecision(0) << (1000 * elapsed)/frequency << endl;

};