/*
*   Include all the needed headers here to run the scenarios
*/

#include <iostream>
#include <string>
#include <fstream>
#include "ContactsBook.h" 
#include"HistoryObject.h"
#include"HistoryObjectList.h"
#include "time.h"
#include<ctime>
using namespace std;

int main() {

    int size_of_list = 0;
    ContactsBook* contactsBook = nullptr;
    HistoryObjectList obj;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1.  Create a contacts list with a given size\n";
        cout << "2.  Add New Contact\n";
        cout << "3.  Merge Duplicates\n";
        cout << "4.  Store To File\n";
        cout << "5.  Load From File\n";
        cout << "6.  Print Contacts Sorted\n";
        cout << "7.  Print Contacts\n";
        cout << "8.  Search contacts\n";
        cout << "9.  Display Count of Contacts\n";
        cout << "10. View search history\n";
        cout << "11. Display top 5 searched\n";
        cout << "12. View details of a single contact\n";
        cout << "13. Update details of a single contact\n";
        cout << "14. Delete a contact\n";
        cout << "15. Create Group\n";
        cout << "16. Add Contact to Group\n";
        cout << "17. View Group\n";
        cout << "18. Remove Contact from Group\n";
        cout << "19. Delete group\n";
        cout << "20. Exit\n";
        cout << "Enter your choice: ";

        string choice;
        getline(cin, choice);

        try {
            int Choice = stoi(choice);

            switch (Choice) {
            case 1: // Create a contacts list with a given size
            {
                cout << "Enter the size of the contacts list: ";
                cin >> size_of_list;
                do {

                    if (cin.fail() || size_of_list < 0 || size_of_list > 1000) {
                        cout << "Invalid input! Must be a valid integer between 0 and 1000: ";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cin >> size_of_list;
                    }
                    else {
                        contactsBook = new ContactsBook(size_of_list);
                        cout << "Contacts list created successfully." << endl;
                        break;
                    }
                } while (true);
            }
            cin.ignore();
            break;
            case 2: // Add New Contact
            {
                string first_name, last_name, phone, email;
                string house, street, city, country;
                Contact contact;

                Address* address_ptr = new Address();

                cout << "Enter first name: ";
                cin >> first_name;
                cout << "Enter last name: ";
                cin >> last_name;
                cout << "Enter phone number: ";
                cin >> phone;
                cout << "Enter email address: ";
                cin >> email;
                cout << "Enter house: ";
                cin >> house;
                cout << "Enter street: ";
                cin >> street;
                cout << "Enter city: ";
                cin >> city;
                cout << "Enter country: ";
                cin >> country;


                contact.set_first_name(first_name);
                contact.set_last_name(last_name);
                contact.set_email_address(email);
                while (!contactsBook->checkUniqueMobileNumber(phone)) {
                    cout << "Phone number already exists. Enter a new phone number: ";
                    cin >> phone;
                }
                while (!contact.set_mobile_number(phone)) {
                    cout << "Enter phone number: ";
                    cin >> phone;
                }
                address_ptr->set_City(city);
                address_ptr->set_House(house);
                address_ptr->set_Street(street);
                address_ptr->set_Country(country);
                contact.set_address(address_ptr);

                contactsBook->add_contact(contact);
                cout << "Contact added successfully.\n";
            }
            cin.ignore();
            break;
            case 3: // Merge Duplicates
            {
                contactsBook->merge_duplicates();
            }
            break;
            case 4: // Store To File
            {
                string file_name;
                cout << "Enter file name to store contacts: ";
                cin >> file_name;
                if (contactsBook->save_to_file(file_name)) {
                    cout << "Contacts stored to file successfully.\n";
                }
                else {
                    cout << "Error!\n";
                }

            }
            cin.ignore();
            break;
            case 5: // Load From File
            {
                string file_name;
                cout << "Enter file name to load contacts: ";
                cin >> file_name;
                if (contactsBook->load_from_file(file_name)) {
                    cout << "Contacts loaded from file successfully.\n";
                }
                else {
                    cout << "Error!\n";
                }
            }
            cin.ignore();
            break;
            case 6: // Print Contacts Sorted
            {
                string sort_choice;
                cout << "Enter sort choice (first_name or last_name): ";
                cin >> sort_choice;
                contactsBook->print_contacts_sorted(sort_choice);
            }
            cin.ignore();
            break;
            case 7: // Print Contacts
            {
                cout << "Printing all contacts:\n";
                for (int i = 0; i < contactsBook->total_contacts(); ++i) {
                    Contact* contact = &contactsBook->copy_contacts_list()[i];
                    if (contact) {
                        cout << "First Name: " << contact->get_first_name() << "\nLast Name: "
                            << contact->get_last_name() << "\nMobile Number: "
                            << contact->get_mobile_number() << "\nEmail Address: "
                            << contact->get_email_address() << endl;

                        contact->get_address()->print_address();
                        cout << endl;
                    }
                }
            }
            break;
            case 8: // Search contacts
            {
                string search_choice;
                cout << "Enter search query : ";
                cin >> search_choice;

                obj.SearchHistory(search_choice);
                Contact* result;

                result = contactsBook->search_contact(search_choice);

                if (result != nullptr) {
                    cout << "Contact found:\n";
                    cout << "First Name: " << result->get_first_name() << "\nLast Name: "
                        << result->get_last_name() << "\nMobile Number: "
                        << result->get_mobile_number() << "\nEmail Address: "
                        << result->get_email_address() << endl;

                    result->get_address()->print_address();
                    cout << endl;
                }
                else {
                    cout << "Contact not found.\n";
                }

            }
            cin.ignore();
            break;
            case 9: // Display Count of Contacts
            {
                cout << "Total contacts: " << contactsBook->total_contacts() << endl;
            }
            break;
            case 10:
            {
                cout << "Search History: " << endl;
                obj.ViewSearchHistory();

            }
            break;
            case 11:
            {
                obj.ViewFrequentlySearched();
            }
            break;
            case 12: // View Contact Details
            {
                int contact_index;
                cout << "Enter the index of the contact to view: ";
                cin >> contact_index;
                if (contact_index >= 0 && contact_index < contactsBook->total_contacts()) {
                    Contact* contact = &contactsBook->copy_contacts_list()[contact_index];
                    cout << "First Name: " << contact->get_first_name() << "\nLast Name: "
                        << contact->get_last_name() << "\nMobile Number: "
                        << contact->get_mobile_number() << "\nEmail Address: "
                        << contact->get_email_address() << endl;
                    contact->get_address()->print_address();
                    cout << endl;
                }
                else {
                    cout << "Invalid index. Please try again." << endl;
                }
            }
            cin.ignore();
            break;
            case 13: // Update Contact Details
            {
                int contact_index;
                cout << "Enter the index of the contact to update: ";
                cin >> contact_index;
                if (contact_index >= 0 && contact_index < contactsBook->total_contacts()) {
                    Contact* contact = &contactsBook->copy_contacts_list()[contact_index];
                    contactsBook->update_contact(contact_index, *contact);
                }
                else {
                    cout << "Invalid index. Please try again." << endl;
                }
            }
            cin.ignore();
            break;
            case 14: // Delete Contact
            {
                int contact_index;
                cout << "Enter the index of the contact to delete: ";
                cin >> contact_index;
                if (contact_index >= 0 && contact_index < contactsBook->total_contacts()) {
                    contactsBook->delete_contact(contact_index);
                    cout << "Contact deleted successfully." << endl;
                }
                else {
                    cout << "Invalid index. Please try again." << endl;
                }
            }
            cin.ignore();
            break;
            case 15: // Create Group
            {
                string name;
                cout << "Enter group name: ";
                cin >> name;
                contactsBook->createGroup(name);
                cout << "Group created Succesfully!";

            }
            cin.ignore();
            break;
            case 16:
            {
                Group* groups = contactsBook->getGroups();
                int totalGroups = contactsBook->getGroupsCount();

                if (totalGroups == 0)
                {
                    cout << "No groups exist. Please create a group first." << endl;
                }
                else
                {
                    for (int i = 0; i < totalGroups; i++)
                    {
                        cout << i + 1 << ". " << groups[i].getName() << endl;
                    }
                    int groupChoice;
                    cout << "Choose a group: " << endl;
                    cin >> groupChoice;

                    if (groupChoice < 1 || groupChoice > totalGroups)
                    {
                        cout << "Invalid group choice. Please choose a valid group." << endl;
                    }
                    else
                    {
                        string groupName = groups[groupChoice - 1].getName();

                        Contact** groupContacts = groups[groupChoice - 1].getContacts();
                        int totalGroupContacts = groups[groupChoice - 1].getContactsCount();
                        Contact* contacts = contactsBook->copy_contacts_list();
                        int totalContacts = contactsBook->total_contacts();
                        if (totalContacts == 0)
                        {
                            cout << "No contacts exist in this group. Please add contacts first." << endl;
                        }
                        else
                        {
                            cout << "Choose a contact to add: " << endl;
                            for (int i = 0; i < totalContacts; i++)
                            {
                                cout << i + 1 << ". " << contacts[i].get_first_name() << " " << contacts[i].get_last_name() << endl;
                            }
                            int contactChoice;
                            cin >> contactChoice;

                            if (contactChoice < 1 || contactChoice > totalContacts)
                            {
                                cout << "Invalid contact choice. Please choose a valid contact." << endl;
                            }
                            else
                            {
                                Contact* chosenContact = &contacts[contactChoice - 1];

                                // Check if the contact already exists in the group
                                bool contactExists = false;
                                for (int i = 0; i < totalGroupContacts; i++)
                                {
                                    if (groupContacts[i]->get_mobile_number() == chosenContact->get_mobile_number())
                                    {
                                        contactExists = true;
                                        break;
                                    }
                                }

                                if (contactExists)
                                {
                                    cout << "Contact already exists in the group. Please choose a different contact." << endl;
                                }
                                else
                                {
                                    contactsBook->addContactToGroup(groupName, chosenContact);
                                    cout << "Contact added to group" << groupChoice << "!" << endl;
                                }
                            }
                        }
                    }
                }
            }
            cin.ignore();
            break;
            case 17:
            {
                Group* groups = contactsBook->getGroups();
                int totalGroups = contactsBook->getGroupsCount();

                if (totalGroups == 0)
                {
                    cout << "No groups exist. Please create a group first." << endl;
                }
                else
                {
                    for (int i = 0; i < totalGroups; i++)
                    {
                        cout << i + 1 << ". " << groups[i].getName() << endl;
                    }
                    int groupChoice;
                    cout << "Choose a group to view: ";
                    cin >> groupChoice;

                    if (groupChoice < 1 || groupChoice > totalGroups)
                    {
                        cout << "Invalid group choice. Please choose a valid group." << endl;
                    }
                    else
                    {
                        Group* group = &groups[groupChoice - 1];
                        cout << "Group Name: " << group->getName() << endl;
                        cout << "Contacts:" << endl;
                        int numContacts = group->getContactsCount();
                        if (numContacts == 0)
                        {
                            cout << "No contacts available in this group." << endl;
                        }
                        else
                        {
                            Contact** contacts = group->getContacts();
                            for (int i = 0; i < numContacts; i++)
                            {
                                cout << "First Name: " << contacts[i]->get_first_name() << endl;
                                cout << "Last Name: " << contacts[i]->get_last_name() << endl;
                                cout << "Phone: " << contacts[i]->get_mobile_number() << endl;
                                cout << "Email: " << contacts[i]->get_email_address() << endl;
                                Address* address = contacts[i]->get_address();
                                cout << "Address: " << address->get_House() << ", " << address->get_Street() << ", " << address->get_City() << ", " << address->get_Country() << endl;
                                cout << endl;
                            }
                        }
                    }
                }
            }
            cin.ignore();
            break;
            case 18:
            {
                Group* groups = contactsBook->getGroups();
                int totalGroups = contactsBook->getGroupsCount();

                if (totalGroups == 0)
                {
                    cout << "No groups exist. Please create a group first." << endl;
                }
                else
                {
                    for (int i = 0; i < totalGroups; i++)
                    {
                        cout << i + 1 << ". " << groups[i].getName() << endl;
                    }
                    int groupChoice;
                    cout << "Choose a group: " << endl;
                    cin >> groupChoice;

                    if (groupChoice < 1 || groupChoice > totalGroups)
                    {
                        cout << "Invalid group choice. Please choose a valid group." << endl;
                    }
                    else
                    {
                        string groupName = groups[groupChoice - 1].getName();

                        Group* selectedGroup = &groups[groupChoice - 1];
                        Contact** contacts = selectedGroup->getContacts();
                        int totalContacts = selectedGroup->getContactsCount();

                        if (totalContacts == 0)
                        {
                            cout << "No contacts available in this group." << endl;
                        }
                        else
                        {
                            cout << "Choose a contact to remove: " << endl;
                            for (int i = 0; i < totalContacts; i++)
                            {
                                cout << i + 1 << ". " << contacts[i]->get_first_name() << "  " << contacts[i]->get_last_name() << endl;
                            }
                            int contactChoice;
                            cin >> contactChoice;

                            if (contactChoice < 1 || contactChoice > totalContacts)
                            {
                                cout << "Invalid contact choice. Please choose a valid contact." << endl;
                            }
                            else
                            {
                                string firstName = contacts[contactChoice - 1]->get_first_name();
                                string lastName = contacts[contactChoice - 1]->get_last_name();
                                contactsBook->removeContactFromGroup(groupName, firstName, lastName);
                                cout << "Contact removed from " << groupName << " succesfully!" << endl;
                            }
                        }
                    }
                }
            }
            cin.ignore();
            break;
            case 19:
            {
                Group* groups = contactsBook->getGroups();
                int totalGroups = contactsBook->getGroupsCount();

                if (totalGroups == 0)
                {
                    cout << "No groups exist. Please create a group first." << endl;
                }
                else
                {
                    for (int i = 0; i < totalGroups; i++)
                    {
                        cout << i + 1 << ". " << groups[i].getName() << endl;
                    }
                    int groupChoice;
                    cout << "Choose a group to delete: ";
                    cin >> groupChoice;

                    if (groupChoice < 1 || groupChoice > totalGroups)
                    {
                        cout << "Invalid group choice. Please choose a valid group." << endl;
                    }
                    else
                    {
                        string groupName = groups[groupChoice - 1].getName();
                        contactsBook->deleteGroup(groupName);
                    }
                }
            }
            cin.ignore();
            break;
            case 20: // Exit
            {
                cout << "Exiting program...\n";
                return 0;
            }
            break;
            default:
            {
                cout << "Invalid choice. Please try again.\n";
            }
            }
            cout << endl;
        }

        catch (invalid_argument)
        {
            cout << "Invalid input. Please enter a number." << endl;
        }

    }

}