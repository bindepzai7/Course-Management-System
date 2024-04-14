#include"User.h"

std::string string_hashing(const std::string& s) {
	std::hash<std::string> hasher;
	return std::to_string(hasher(s));
}

void changePassword(LinkedList<User>& userList, const std::string& username, const std::string& new_password) {
	Node<User>* curr = userList.head;
	if (curr == nullptr) return;
	while (curr && curr->data.username != username)
		curr = curr->next;

	if (curr == nullptr) {
		std::cout << "User: " << username << " not found" << std::endl;
		return;
	}
	curr->data.password = string_hashing(new_password);
	return;
}

LinkedList<User> readUserFromCSV(const std::string& filename) {
	LinkedList<User> user;

	std::ifstream fin(filename);
	if (!fin.is_open()) {
		std::cout << "Failed to open file: " << filename << std::endl;
		return user;
	}

	std::string line;
	std::getline(fin, line);
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

bool check_login(const LinkedList<User>& users, const std::string& username, const std::string& password) {
	Node<User>* head = users.head;
	while (head && head->data.username != username) {
		head = head->next;
	}
	if (head == nullptr) return false;
	else {
		std::string hash_string = string_hashing(password);
		if (hash_string == head->data.password) return true;
		return false;
	}
}

void updateUser2CSVfile(const std::string& filename, const LinkedList<User>& userList) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cout << "Failed to open file: " << filename << std::endl;
		return;
	}

	Node<User>* head = userList.head;
	file << "username" << ',' << "password" << std::endl;
	while (head != nullptr) {
		file << head->data.username << ',' << head->data.password << std::endl;
		head = head->next;
	}
	file.close();
}
