#include "HistoryObject.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;

HistoryObject::HistoryObject()
{
	searched = "";
	time = "";
	count = 0;
}

string HistoryObject::getSearched()
{
	return searched;
}
string HistoryObject::getTime()
{
	return time;
}
int HistoryObject::getCount()
{
	return count;
}
void  HistoryObject::setCount(int n)
{
	count = n;
}
void  HistoryObject::setSearched(string s)
{
	searched = s;
}
void  HistoryObject::setTime(string t)
{
	time = t;
}

bool HistoryObject::equals(HistoryObject obj)
{
	if (this->searched == obj.searched)
	{
		return true;
	}
	else
	{
		return false;
	}
}