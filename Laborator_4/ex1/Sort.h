#pragma once
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <cstdarg>
#include<random>
#include<time.h>

using namespace std;

class Sort

{private:
    // add data members
    int * list;
    int numberOfElementsList;
    

public:

    // add constuctors

    Sort(int minValue, int maxValue, int numberOfElements);

    Sort();

    Sort(int * vector, int numberOfElementsVector);

    Sort(int numberOfElements, ...);

    Sort(const char* stringList);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};
