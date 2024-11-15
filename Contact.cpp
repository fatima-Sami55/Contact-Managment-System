#include "Contact.h"

/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/

Contact::Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->mobile_number = mobile_number;
	this->email_address = email_address;
	if (address != nullptr) {
		this->address = new Address(*address);
	}
	else {
		this->address = nullptr;
	}
}


/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size).
*   Check in phone number setter, Phone number must be 11 digits
*/

void Contact::set_address(Address* A) {
	address = A;
}
void Contact::set_first_name(string f_name) {
	if (!(f_name == " ")) {
		first_name = f_name;
	}

}
void Contact::set_last_name(string l_name) {
	if (!(l_name == " ")) {
		last_name = l_name;
	}

}
void Contact::set_email_address(string e_address) {
	if (!(e_address == " ")) {
		email_address = e_address;
	}

}
bool Contact::set_mobile_number(string m_number) {
	if (m_number.length() == 11) {
		mobile_number = m_number;
		return true;
	}
	else {
		cout << "Invalid phone number length. Phone number must be 11 digits." << endl;
		return false;
	}
}



string Contact::get_first_name() {
	return first_name;
}
string Contact::get_last_name() {
	return last_name;
}
string Contact::get_mobile_number() {
	return mobile_number;
}
string Contact::get_email_address() {
	return email_address;
}
Address* Contact::get_address() {
	return address;
}


/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/

bool Contact::equals(Contact contact) {
	if (!this->address->equals(*contact.address)) {
		return false;
	}

	if (this->first_name != contact.first_name) {
		return false;
	}
	if (this->last_name != contact.last_name) {
		return false;
	}
	if (this->email_address != contact.email_address) {
		return false;
	}
	if (this->mobile_number != contact.mobile_number) {
		return false;
	}


	return true;
}

/*
	Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
*/
Contact* Contact::copy_contact() {
	Contact* new_contact = new Contact();


	new_contact->first_name = this->first_name;
	new_contact->last_name = this->last_name;
	new_contact->mobile_number = this->mobile_number;
	new_contact->email_address = this->email_address;


	if (this->address != nullptr) {
		new_contact->address = new Address(
			this->address->get_House(),
			this->address->get_Street(),
			this->address->get_City(),
			this->address->get_Country()
		);
	}
	else {
		new_contact->address = nullptr;
	}

	return new_contact;
}