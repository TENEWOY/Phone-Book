#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Contact {
public:
	string name;
	string phone;

	Contact(string name, string phone) : name(name), phone(phone) {}
};

class PhoneBook {
private:
	vector<Contact> contacts;
public:
	void addContact(const string& name, const string& phone);
	void showContacts();
	void findContact(const string& query);
	void deleteContact(int index);
	void saveToFile(const string& filename);
	void loadFromFile(const string& filename);
};
