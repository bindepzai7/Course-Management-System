#ifndef USER_H
#define USER_H 
#include <fstream>
#include <sstream>
#include <string>
#include <functional>

#include "function.h"
class User {
public:
	std::string username;
	std::string password;

	User() :username(""), password("") {}
	User(const std::string& us,const std::string& pw)
		: username(us), password(pw) {}

};
//

std::string hash_password(const std::string& password) {
	std::hash<std::string> hasher;
	return std::to_string(hasher(password));
}

void write_csv(const std::string& filename, const LinkedList<User>& users) {
	std::ofstream file(filename);		
	if (!file.is_open()) {
		std::cout << "Failed to open file: " << filename << std::endl;
		return;
	}

	Node<User>* head = users.head;
	while (head) {
		file << head->data.username << ',' << head->data.password << std::endl;
		head = head->next;
	}
	file.close();
}

void change_password(LinkedList<User>& users, const std::string& username, const std::string& new_password) {
	Node<User>* head = users.head;
	while (head && head->data.username != username)
		head = head->next;
	if (head == nullptr) {
		std::cout << "User: " << username << " not found" << std::endl;
		return;
	}
	head->data.password = hash_password(new_password);
	return;
}
LinkedList<User> read_csv(const std::string& filename) {
	LinkedList<User> user;

	std::ifstream fin(filename);
	if (!fin.is_open()) {
		std::cout << "Failed to open file: " << filename << std::endl;
		return user;
	}

	std::string line;
	while (std::getline(fin, line)) {
		std::stringstream ss(line);
		std::string username, password;
		if (std::getline(ss, username, ',') && std::getline(ss, password)) {
			user.addNodeAtFront(User(username, password));
		}
	}

	fin.close();
	return user;
}

bool login(const LinkedList<User>& users, const std::string& username, const std::string& password) {
	Node<User>* head = users.head;
	while (head && head->data.username != username) {
		head = head->next;
	}
	if (head == nullptr) return false;
	else {
		std::string hash_string = hash_password(password);
		if (hash_string == head->data.password) return true;
		return false;
	}
}


#endif