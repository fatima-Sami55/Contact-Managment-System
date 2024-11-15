#include "ContactsBook.h"
#include<fstream>


ContactsBook::ContactsBook(int size_of_list) {
	size_of_contacts = size_of_list;
	contacts_count = 0;
	contacts_list = new Contact[size_of_contacts];
	groups_count = 0;
	int size_of_groups = 100;
	groups = new Group[size_of_groups]; // Allocate memory for Group objects

	for (int i = 0; i < size_of_contacts; i++) {
		Address* address = new Address("", "", "", "");
		contacts_list[i] = Contact("", "", "", "", address);
	}

	// Properly initialize each Group object within the groups array
	for (int i = 0; i < size_of_groups; i++) {
		string groupName = "Group " + to_string(i);
		groups[i] = Group(groupName, &contacts_list, size_of_list); // Pass initialized contact list to Group constructor
	}
}

ContactsBook::~ContactsBook() {
	delete[] contacts_list;
	delete[] groups;
}

void ContactsBook::add_contact(const Contact& contact)
{
	/*
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/
	if (full()) {
		resize_list();
	}

	contacts_list[contacts_count] = contact;
	contacts_count++;
	return;

}

int ContactsBook::total_contacts()
{
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
	return contacts_count;
}

bool ContactsBook::full()
{
	/*
	* Return true if list is full, false otherwise
	*/

	/*
	*	Remove this return false; before writing your code
	*/

	if (contacts_count == size_of_contacts)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ContactsBook::resize_list()
{
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/

	int new_size = size_of_contacts * 2;
	Contact* temp_contacts_list = new Contact[new_size];

	for (int i = 0; i < contacts_count; ++i) {
		temp_contacts_list[i] = contacts_list[i];
	}

	delete[] contacts_list;
	contacts_list = temp_contacts_list;
	this->size_of_contacts = new_size;
}

Contact* ContactsBook::search_contact(const string s)
{
	//check if string or its subsequence matches any attribute
	for (int i = 0; i < contacts_count; i++)
	{
		if (checkSubsequence(s, contacts_list[i].get_first_name()))
		{
			return &contacts_list[i];
		}
		if (checkSubsequence(s, contacts_list[i].get_last_name()))
		{
			return &contacts_list[i];
		}
		if (checkSubsequence(s, contacts_list[i].get_mobile_number()))
		{
			return &contacts_list[i];
		}
		if (checkSubsequence(s, contacts_list[i].get_email_address()))
		{
			return &contacts_list[i];
		}
		if (checkSubsequence(s, contacts_list[i].get_address()->get_City()))
		{
			return &contacts_list[i];
		}
		if (checkSubsequence(s, contacts_list[i].get_address()->get_Country()))
		{
			return &contacts_list[i];
		}
		if (checkSubsequence(s, contacts_list[i].get_address()->get_House()))
		{
			return &contacts_list[i];
		}
		if (checkSubsequence(s, contacts_list[i].get_address()->get_Street()))
		{
			return &contacts_list[i];
		}
	}
	return nullptr;
}

bool ContactsBook::checkSubsequence(const string s, const string r) {
	// Function to check if the string s is a subsequence of string r
	int j = 0;
	for (int i = 0; i < r.length(); i++) {
		if (r[i] == s[j]) {
			j++;
			if (j == s.length()) {
				return true; // Entire s is found as a subsequence in r
			}
		}
	}
	return false; // s is not a subsequence of r
}

Contact* ContactsBook::copy_contacts_list() const
{
	Contact* copied_contacts = new Contact[contacts_count];
	if (!copied_contacts) {
		// Handle memory allocation failure
		return nullptr;
	}

	// Copy each contact from the original array to the new array
	for (int i = 0; i < contacts_count; ++i) {
		copied_contacts[i] = contacts_list[i];
	}

	// Return the pointer to the copied array
	return copied_contacts;
}

void ContactsBook::print_contacts_sorted(string choice)
{
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
	Contact* sorted_contacts = copy_contacts_list();

	if (!sorted_contacts) {
		// Handle copy failure
		return;
	}

	// Sort the copied array based on the provided choice
	sort_contacts_list(sorted_contacts, choice);

	// Print the sorted contacts

	for (int i = 0; i < contacts_count; ++i) {
		cout << "First Name: " << sorted_contacts[i].get_first_name() << "\nLast Name: "
			<< sorted_contacts[i].get_last_name() << "\nMobile Number: "
			<< sorted_contacts[i].get_mobile_number() << "\nEmail Address: "
			<< sorted_contacts[i].get_email_address() << endl;

		sorted_contacts[i].get_address()->print_address();
		cout << endl;
	}

	// Free the memory allocated for the copied array
	delete[] sorted_contacts;
}

void ContactsBook::sort_contacts_list(Contact* contacts_list, string choice)
{
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/

	bool sortByFirstName = (choice == "first_name");

	// Perform bubble sort
	for (int i = 0; i < contacts_count; ++i) {
		for (int j = 0; j < contacts_count - i - 1; ++j) {
			// Compare the first name or last name strings
			if (sortByFirstName) {
				if (contacts_list[j].get_first_name() > contacts_list[j + 1].get_first_name()) {
					// Swap contacts
					Contact temp = contacts_list[j];
					contacts_list[j] = contacts_list[j + 1];
					contacts_list[j + 1] = temp;
				}
			}
			else {
				if (contacts_list[j].get_last_name() > contacts_list[j + 1].get_last_name()) {
					// Swap contacts
					Contact temp = contacts_list[j];
					contacts_list[j] = contacts_list[j + 1];
					contacts_list[j + 1] = temp;
				}
			}
		}
	}


}

void ContactsBook::merge_duplicates()
{
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts

	int merged = 0;
	string contact_merged;

	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			if (contacts_list[i].equals(contacts_list[j]))
			{
				for (int m = j; m < contacts_count - 1; m++)
				{
					contacts_list[m] = contacts_list[m + 1];
				}
				contacts_count--;
				merged++;
				j--;
				contact_merged = contacts_list[i].get_first_name();
				cout << contact_merged << " was merged. " << endl;
			}
		}
	}
	cout << merged << " number of contacts were merged." << endl;

}

bool ContactsBook::load_from_file(string file_name)
{
	/*
	*	Read contacts back from file in the same format
	*	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/

	// Open the file for reading
	ifstream fin;
	fin.open(file_name);

	// Check if the file is opened successfully
	if (!fin.is_open()) {
		cout << "Error: Unable to open file " << file_name << endl;
		return false;
	}
	else {
		int num_contacts;
		fin >> num_contacts;
		fin.ignore();


		for (int i = 0; i < num_contacts; ++i) {
			// Read contact attributes (except address) in comma-separated format
			string first_name, last_name, phone, email;
			string house, street, city, country;
			getline(fin, first_name, ',');
			getline(fin, last_name, ',');
			getline(fin, phone, ',');
			getline(fin, email, ',');
			getline(fin, house, ',');
			getline(fin, street, ',');
			getline(fin, city, ',');
			getline(fin, country);

			// Create a new Contact object and Address object
			Address* address_ptr = new Address(house, street, city, country);
			Contact contact(first_name, last_name, phone, email, address_ptr);
			contact.set_address(address_ptr);
			add_contact(contact);

		}
		return true;
	}
	// Close the file
	fin.close();
}

bool ContactsBook::save_to_file(string file_name)
{
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
	ofstream fout;

	fout.open(file_name, ios::out);

	if (!fout.good()) {
		cout << "Error: Unable to open file " << file_name << endl;
		return false;
	}
	else {

		fout << contacts_count << endl;

		for (int i = 0; i < contacts_count; ++i) {
			fout << contacts_list[i].get_first_name() << "," << contacts_list[i].get_last_name() << ","
				<< contacts_list[i].get_mobile_number() << "," << contacts_list[i].get_email_address() << "," << contacts_list[i].get_address()->get_House() << "," << contacts_list[i].get_address()->get_Street() << ","
				<< contacts_list[i].get_address()->get_City() << "," << contacts_list[i].get_address()->get_Country() << endl;
		}

		fout.close();
		return true;
	}
}

void ContactsBook::delete_contact(int index) {
	if (index >= 0 && index < total_contacts()) {
		// Shift all contacts after the deleted contact one position to the left
		for (int i = index; i < total_contacts() - 1; ++i) {
			contacts_list[i] = contacts_list[i + 1];
		}
		// Reduce the total count of contacts
		--contacts_count;

		for (int i = 0; i < groups_count; ++i) {
			string firstName = contacts_list[index].get_first_name();
			string lastName = contacts_list[index].get_last_name();
			groups[i].removeContact(firstName, lastName);
			cout << "Also removed from all the groups! " << endl;
		}
	}
}

void ContactsBook::update_contact(int index, Contact& contact) {
	if (index >= 0 && index < total_contacts()) {
		string first_name, last_name, phone, email;
		string house, street, city, country;
		Address* address_ptr = new Address();
		cout << "Enter new first name: ";
		cin >> first_name;
		cout << "Enter new last name: ";
		cin >> last_name;
		cout << "Enter new phone number: ";
		cin >> phone;
		cout << "Enter new email address: ";
		cin >> email;
		cout << "Enter new house: ";
		cin >> house;
		cout << "Enter new street: ";
		cin >> street;
		cout << "Enter new city: ";
		cin >> city;
		cout << "Enter new country: ";
		cin >> country;
		contact.set_first_name(first_name);
		contact.set_last_name(last_name);
		contact.set_email_address(email);
		while (!contact.set_mobile_number(phone)) {
			cout << "Enter phone number: ";
			cin >> phone;
		}
		address_ptr->set_City(city);
		address_ptr->set_House(house);
		address_ptr->set_Street(street);
		address_ptr->set_Country(country);
		contact.set_address(address_ptr);
		contacts_list[index] = contact;
		cout << "Contact updated successfully." << endl;
		print_contacts_sorted("last_name");
	}
	else {
		cout << "Invalid index. Please try again." << endl;
	}
}

void ContactsBook::createGroup(const string& name) {
	if (groups_count < 100) {
		groups[groups_count].setName(name);
		groups_count++;
	}
}

void ContactsBook::addContactToGroup(const string& groupName, Contact* contact) {
	for (int i = 0; i < groups_count; i++) {
		if (groups[i].getName() == groupName) {
			groups[i].addContact(contact);
			break;
		}
	}
}

void ContactsBook::removeContactFromGroup(const string& groupName, const string& firstName, const string& lastName) {
	// Get the group object using the group name
	Group* group = getGroup(groupName);

	// Check if the group exists
	if (group != nullptr) {
		// Iterate through contacts in the group
		group->removeContact(firstName, lastName);
	}
	else {
		cout << "Group not found." << endl;
	}
}

Group* ContactsBook::getGroup(const string& groupName) {
	for (int i = 0; i < groups_count; i++) {
		if (groups[i].getName() == groupName) {
			return &groups[i];
		}
	}
	return nullptr;
}

void ContactsBook::deleteGroup(const string& groupName) {
	// Find the group
	int groupIndex = -1;
	for (int i = 0; i < groups_count; ++i) {
		if (groups[i].getName() == groupName) {
			groupIndex = i;
			break;
		}
	}

	// If the group is found
	if (groupIndex != -1) {
		// Remove all contacts from the group
		Contact** contacts = groups[groupIndex].getContacts();
		int numContacts = groups[groupIndex].getContactsCount();
		for (int i = 0; i < numContacts; ++i) {
			delete contacts[i]; // Delete each contact
		}
		delete[] contacts; // Delete the contacts array

		// Remove the group
		for (int i = groupIndex; i < groups_count - 1; ++i) {
			groups[i] = groups[i + 1]; // Shift groups to the left
		}
		groups_count--; // Update the count of groups

		cout << "Group removed successfully!" << endl;
	}
}