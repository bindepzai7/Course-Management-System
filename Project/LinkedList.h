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
};






#endif