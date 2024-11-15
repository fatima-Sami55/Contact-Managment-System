#pragma once
#include "Address.h"
#include "Contact.h"
#include "GROUP.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB


class ContactsBook {
private:
	Contact* contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count; // total contacts currently stored, next contact will be 
	Group* groups;
	int groups_count;
	// stored at this count plus 1 index

public:

	ContactsBook() {}
	~ContactsBook();

	ContactsBook(int size_of_list);
	void add_contact(const Contact& contact);
	int total_contacts();
	int getGroupsCount() { return groups_count; }

	Contact* search_contact(string phone);
	/*Contact * search_contact(const string s); */

		void print_contacts_sorted(string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal, this means if

/*
*  This function loads contacts from the given file (see details in ContactsBook.cpp)
*/
	bool load_from_file(string file_name);
	bool save_to_file(string file_name);
	Contact* copy_contacts_list() const;

	bool checkSubsequence(string s, string r);
	void delete_contact(int index);
	void update_contact(int index, Contact& contact);
	void create_group(const string& group_name);

	void createGroup(const string& name);
	void addContactToGroup(const string& groupName, Contact* contact);
	void removeContactFromGroup(const string& groupName, const string& firstName, const string& lastName);
	Group* getGroup(const string& groupName);
	Group* getGroups() {
		return groups;
	}
	void deleteGroup(const string& groupName);
	bool checkUniqueMobileNumber(const string& phone) {
		for (int i = 0; i < contacts_count; i++) {
			if (contacts_list[i].get_mobile_number() == phone) {
				return false; // Phone number already exists
			}
		}
		return true; // Phone number is unique
	}

private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact* contacts_list, string choice);
};