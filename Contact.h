#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

#include "Address.h"

using namespace std;


class Contact {
private:
    string first_name;
    string last_name;
    string mobile_number;
    string email_address;
    Address* address;

public:
    bool equals(Contact contact);
    Contact* copy_contact();

    Contact() : address(nullptr) {} // Default constructor with address initialized to nullptr
    Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address);

    // Setters
    void set_first_name(string f_name);
    void set_last_name(string l_name);
    bool set_mobile_number(string m_number);
    void set_email_address(string e_address);
    void set_address(Address* A);

    // Getters
    string get_first_name();
    string get_last_name();
    string get_mobile_number();
    string get_email_address();
    Address* get_address();
};