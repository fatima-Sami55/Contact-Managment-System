#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
	string House;
	string Street;
	string City;
	string Country;

public:
	bool equals(const Address& address);
	void print_address();
	Address copy_address();

	//constructors
	Address(string house, string street, string city, string country);
	Address() {}

	//setters
	void set_House(string house);
	void set_Street(string street);
	void set_City(string city);
	void set_Country(string country);

	//getters
	string get_House() const;
	string get_Street() const;
	string get_City() const;
	string get_Country() const;


};