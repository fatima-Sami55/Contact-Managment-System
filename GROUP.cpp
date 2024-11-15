#include "Group.h"

Group::Group(const string& name, Contact** contactsList, int listSize) : name(name), contactsCount(0), contactsCapacity(listSize) {
    // Allocate memory for contacts array
    contacts = new Contact * [contactsCapacity];
    // Copy contacts from the contactsList to the contacts array
    for (int i = 0; i < contactsCapacity; ++i) {
        contacts[i] = contactsList[i];
    }
}

void Group::addContact(Contact* contact) {
    contacts[contactsCount] = new Contact(contact->get_first_name(), contact->get_last_name(), contact->get_mobile_number(), contact->get_email_address(), contact->get_address());
    contactsCount++;
}

void Group::removeContact(const string& firstName, const string& lastName) {
    for (int i = 0; i < contactsCount; i++) {
        if (contacts[i]->get_first_name() == firstName && contacts[i]->get_last_name() == lastName) {
            delete contacts[i];
            // Shift remaining contacts to fill the gap
            for (int j = i; j < contactsCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            // Update contacts count
            contactsCount--;
            cout << "Contact removed from group successfully." << endl;
            return;
        }
    }
    cout << "Contact not found in group." << endl;
}