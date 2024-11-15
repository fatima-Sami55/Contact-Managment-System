#include "HistoryObjectList.h"
#include"HistoryObject.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#pragma warning(disable : 4996) 

using namespace std;

int HistoryObjectList::size = 0;
//constructor
HistoryObjectList::HistoryObjectList()
{
    history = new HistoryObject[MAX_HISTORY_SIZE];
    viewed = new HistoryObject[MAX_HISTORY_SIZE];
}
//destructor
HistoryObjectList::~HistoryObjectList() {
    // Free allocated memory
    delete[] history;
    delete[] viewed;
}

void HistoryObjectList::ViewSearchHistory()
{
    int counter = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        cout << counter << ". " << endl;
        cout << "Searched: ";
        cout << history[i].getSearched() << endl;
        cout << "Time: ";
        cout << history[i].getTime() << endl;
        counter++;
    }
}


void HistoryObjectList::SearchHistory(string s)
{
    // current date and time on the current system
    time_t now = time(0);

    // convert now to string form
    char* date_time = ctime(&now);

    history[size].setSearched(s);
    history[size].setTime(date_time);

    size++;
}
struct TempObject {
    string searched;
    int count;
};

//sorting using templates
template <typename T>
void HistoryObjectList::sort(T* A)
{
    //sort the array based on search count
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (A[j].count < A[j + 1].count) {
                TempObject temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }


}

void HistoryObjectList::ViewFrequentlySearched()
{
    // Temporary array to keep track of search counts
    int maxSize = MAX_HISTORY_SIZE;

    TempObject* tempArray = new TempObject[maxSize];


    // Initialize temporary array
    for (int i = 0; i < size; ++i) {
        tempArray[i].searched = history[i].getSearched();
        tempArray[i].count = 1; // Initialize count to 1 for each entry
    }

    // Count occurrences of each search term
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (tempArray[i].searched == tempArray[j].searched) {
                ++tempArray[i].count;
                // Remove duplicate entry
                for (int k = j; k < size - 1; ++k) {
                    tempArray[k].searched = tempArray[k + 1].searched;
                    tempArray[k].count = tempArray[k + 1].count;
                }
                --size; // Decrease size to account for removed duplicate
                --j; // Adjust index for the removed duplicate
            }
        }
    }
    sort<TempObject>(tempArray);



    // Display top 5 searched items
    cout << "Your top 5 searches: " << endl;
    for (int i = 0; i < min(5, size); ++i) {
        cout << i + 1 << ". " << tempArray[i].searched << " - Count: " << tempArray[i].count << endl;
    }

    delete[] tempArray;

}