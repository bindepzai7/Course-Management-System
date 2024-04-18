#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include<string>
#include <functional>

template <class T>
class Node {
public:
    T data;
    Node* next = nullptr;
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
        Node<T>* cur = head;
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

    bool pop_head(T& data) {
        if (!head) return false;
        data = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    void deleteAt(int index) {
        if (!this->head) return;
        Node<T>* cur = this->head;
        for (int i = 1; i < index ; ++i) {
            if (cur->next != NULL) {
                cur = cur->next;
            }
            else return;
        }

        if (index == 0) {
            this->head = this->head->next;
            delete cur;
            return;
        }

        if (cur and cur->next != NULL) {
            Node<T>* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
    }

    void empty() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
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
    //get data from list based on Username
    

    void removeNodeByData(T data) {
        if (head == nullptr) return;
        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            //Node<T>* prev = nullptr;
            Node<T>* curr = head;
            /*while (prev && curr->next && !(curr->next->data == data)) {
                prev = curr;
                curr = curr->next;
            }
            if (curr == nullptr) {
                std::cout << "Don't exist this data" << std::endl;
            }
            else if (!curr->next) {
                prev->next = curr->next;
                delete curr;
            }*/
            while (curr->next) {
                if (curr->next->data == data) {
                    Node<T>* tmp = curr->next;
                    curr->next = tmp->next;
                    delete tmp;
                    return;
                }
            }
        }
    }
    //function use for dropdownlist (if its needed)
    void push_tail(const T &data) {
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

    
    
    int sizeoflist() {
        int n = 0;
        Node<T>* cur = head;
        while (cur) {
            cur = cur->next;
            n++;
        }
        return n;
    }
};


#endif;