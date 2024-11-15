#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;

class HistoryObject
{
	string searched;
	string time;
	int count;
public:
	HistoryObject();
	void setCount(int n);
	void setSearched(string s);
	void setTime(string t);
	string getSearched();
	string getTime();
	int getCount();
	bool equals(HistoryObject obj);
};