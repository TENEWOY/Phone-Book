#include <iostream>
#include "Phone.h"

int main() {
	setlocale(LC_ALL, "Rus");
	PhoneBook pb;
	int choice;
	string name, phone, query;
	string filename = "contacts.txt";

	pb.loadFromFile(filename);

	while (true) {
		cout << "\n--- Телефонная книга ---\n";
		cout << "1. Добавить контакт\n";
		cout << "2. Показать все контакты\n";
		cout << "3. Найти контакт\n";
		cout << "4. Удалить контакт\n";
		cout << "5. Сохранить и выйти\n";
		cout << "Выбор: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			cout << "Имя: ";
			getline(cin, name);
			cout << "Телефон: ";
			getline(cin, phone);
			pb.addContact(name, phone);
			break;
		case 2:
			pb.showContacts();
			break;
		case 3:
			cout << "Введите имя или номер: ";
			getline(cin, query);
			pb.findContact(query);
			break;
		case 4:
			pb.showContacts();
			cout << "Введите номер строки для удаления: ";
			int index;
			cin >> index;
			cin.ignore();
			pb.deleteContact(index);
			break;
		case 5:
			pb.saveToFile(filename);
			cout << "До свидания!\n";
			return 0;
		default:
			cout << "Неверный выбор\n";
		}
	}

	return 0;
}