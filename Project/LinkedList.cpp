

#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::addNodeAtFront(T data) {
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

template <class T>
void LinkedList<T>::addNodeInAscending(T data) {
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

template <class T>
void LinkedList<T>::display() {
    Node<T>* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <class T>
bool LinkedList<T>::findXData(T data) {
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