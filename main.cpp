//
// Created by hellf on 04.03.2021.
//


#include <iostream>
#include "main.h"
#include "ArrayList/ArrayList.h"
#include "MainMenu/Reader.h"


using namespace std;
 int main(){
 Reader reader("data.txt");
 int *array = new int[reader.arraySize];
 array = reader.arr;
 for(int i = 0; i<reader.arraySize; i++){
     cout<<array[i];
 }

}