#include "Address.h"
#include<fstream>


//constructor
Address::Address(string house, string street, string city, string country)
{
	House = house;
	Street = street;
	City = city;
	Country = country;
}


//setters
void Address::set_House(string house)
{
	House = house;
}
void Address::set_Street(string street)
{
	Street = street;
}
void Address::set_City(string city)
{
	City = city;
}
void Address::set_Country(string country)
{
	Country = country;
}

//getters
string Address::get_House() const
{
	return House;
}
string Address::get_Street() const
{
	return Street;
}
string Address::get_City() const
{
	return City;
}
string Address::get_Country() const
{
	return Country;
}

/*
*	Implement the equals function that takes an Address object and checks if it is equal to
*	current object refered by (this pointer)
*	Two addresses are equal if all the attributes of addresses are equal
*/



bool Address::equals(const Address& address)
{
	if (this->House != address.House)
	{
		return false;
	}
	if (this->Street != address.Street)
	{
		return false;
	}
	if (this->City != address.City)
	{
		return false;
	}
	if (this->Country != address.Country)
	{
		return false;
	}

	return true;
}

void Address::print_address() {
	cout << "The address is\n" << "House: " << House << "\nStreet: " << Street << "\nCity: " << City << "\nCountry: " << Country << endl;
}

Address Address::copy_address()
{
	return *this;
}