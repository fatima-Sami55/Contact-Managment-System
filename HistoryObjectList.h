#pragma once
// HistoryObjectList.h
#pragma once
#include "HistoryObject.h"
#include <iostream>
#include<ctime>
#include <string>
using namespace std;

class HistoryObjectList
{
    HistoryObject* history;
    HistoryObject* viewed;
    int MAX_HISTORY_SIZE = 100;

public:
    static int size;

    HistoryObjectList();
    ~HistoryObjectList();
    void SearchHistory(string s);
    void ViewSearchHistory();
    void ViewFrequentlySearched();

    template <typename T>
    void sort(T* A);

};