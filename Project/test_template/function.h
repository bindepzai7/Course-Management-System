#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
template <class T>
struct Node {
    T data;
    Node* next;
};

template <class T>
class LinkedList {
public:
    Node<T>* head;
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }


    void addNodeAtFront(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }


    //Additional functional NTU's made (please delete unwanted ones)
    /////////////////////////////////////////////////////////////

    void push_head(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    //the following function is called in AddCourse.cpp
    void push_tail(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void pop_head(T& data) {
        if (!head) return;
        data = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_tail(T& data) {
        if (!head) return;
        Node<T>* temp = head;
        while (temp->next and temp->next->next) {
            temp = temp->next;
        }
        if (!temp->next) {
            data = temp->data;
            head = nullptr;
            delete temp;
        }
        else {
            data = temp->next->data;
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void deleteAt(int index) {
        Node<T>* cur = this->head;
        for (int i = 1; i < index && cur->next != NULL; ++i) {
            cur = cur->next;
        }
        if (cur->next != NULL) {
            Node<T>* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
    }

    ///////////////////////////////////////////////////////


    void addNodeInAscending(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            if (data < head->data) {
                newNode->next = head;
                head = newNode;
            }
            else if (data == head->data) return;
            else {
                Node<T>* curr = head;
                while (curr->next != nullptr && curr->next->data < data) {
                    curr = curr->next;
                }
                if (curr->next && curr->next->data == data) return;
                newNode->next = curr->next;
                curr->next = newNode;
            }
        }
    }

    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    bool isXDatainlist(T data) {
        if (head == nullptr) return false;
        if (!(head->data != data)) return true;
        Node<T>* cur = head;
        while (cur)
        {
            if (!(cur->data != data)) return true;
            cur = cur->next;
        }
        return false;
    }

    void removeNodeByData(T data) {
        if (head == nullptr) return;
        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        else {

            Node<T>* prev = nullptr;
            Node<T>* curr = head;
            while (curr->next && !(curr->next->data == data)) {
                prev = curr;
                curr = curr->next;
            }
            if (curr == nullptr) return;
            else {
                prev->next = curr->next;
                delete curr;
            }
        }
    }
};
//
//class Student {
//public:
//    std::string studentID;
//    std::string password;
//    bool studentGender; // 0 is male, 1 is female
//    std::string socialID;
//    // Default constructor
//    Student() : studentID(""), password(""), studentGender(false), socialID("") {}
//    //Constructor with studentID and password
//    /*Student(const std::string& studentID, const std::string& password) : studentID(studentID), password(password) {}*/
//    // Constructor with parameters
//    Student(const std::string& studentID, const std::string& password, bool studentGender, const std::string& socailID)
//        : studentID(studentID), password(password), studentGender(studentGender), socialID(socialID) {}
//
//
//    bool operator==(const Student& s2) const {
//        return studentID == s2.studentID/*&&password==s2.password*/;
//    }
//
//    bool operator>(const Student& s2) const {
//        return studentID > s2.studentID;
//    }
//
//    bool operator<(const Student& s2) const {
//        return studentID < s2.studentID;
//    }
//    bool operator!=(const Student& s2) const {
//        return studentID != s2.studentID || password != s2.password;
//    }
//};

#endif