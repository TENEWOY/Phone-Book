#include "Phone.h"

void PhoneBook::addContact(const string& name, const string& phone) {
	contacts.emplace_back(name, phone);
	std::cout << "������� ��������!\n";
}

void PhoneBook::showContacts() {
	if (contacts.empty()) {
		std::cout << "���������� ����� �����.\n";
		return;
	}
	for (int i = 0; i < contacts.size(); ++i) {
		std::cout << i + 1 << ") " << contacts[i].name << " - " << contacts[i].phone << "\n";
	}
}

void PhoneBook::findContact(const string& query) {
	bool found = false;
	for (const auto& c : contacts) {
		if (c.name == query || c.phone == query) {
			std::cout << "�������: " << c.name << " - " << c.phone << "\n";
			found = true;
		}
	}
	if (!found) std::cout << "������� �� ������.\n";
}

void PhoneBook::deleteContact(int index) {
	if (index > 0 && index <= contacts.size()) {
		contacts.erase(contacts.begin() + index - 1);
		std::cout << "������� �����.\n";
	}
	else {
		std::cout << "�������� ������.\n";
	}
}

void PhoneBook::saveToFile(const string& filename) {
	ofstream file(filename);
	for (const auto& c : contacts) {
		file << c.name << "," << c.phone << "\n";
	}
	file.close();
	std::cout << "�������� ��������� � " << filename << endl;
}

void PhoneBook::loadFromFile(const string& filename) {
	contacts.clear();
	ifstream file(filename);
	string line;
	while (getline(file, line)) {
		size_t comma = line.find(',');
		if (comma != string::npos) {
			string name = line.substr(0, comma);
			string phone = line.substr(comma + 1);
			contacts.emplace_back(name, phone);
		}
	}
	file.close();
	std::cout << "�������� ��������� �� " << filename << endl;
}