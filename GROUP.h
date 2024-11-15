#pragma once
#pragma once

#ifndef GROUP_H
#define GROUP_H

#include <string>
#include "Contact.h"

using namespace std;

class Group {
public:
    Group() {}
    Group(const string& name, Contact** contactsList, int listSize);
    void addContact(Contact* contact);
    void removeContact(const string& firstName, const string& lastName);

    string getName() const { return name; }
    Contact** getContacts() const { return contacts; }
    int getContactsCount() const { return contactsCount; }
    void setName(const string& Name) { name = Name; }


private:
    string name;
    Contact** contacts;
    int contactsCount;
    int contactsCapacity;
};

#endif // GROUP_H