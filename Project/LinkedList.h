#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>


template <class T>
class Node {
public:
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

    void insert(T data) {
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

    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};






#endif