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
    LinkedList();

    ~LinkedList();

    void addNodeAtFront(T data);

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


    void addNodeInAscending(T data);

    void display();

    bool isXDatainlist(T data);
};



#endif