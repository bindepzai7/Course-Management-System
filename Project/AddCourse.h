#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


#include <time.h>
struct Date {
	int day;
	int month;
	int year;

	Date() {
		day = 1;
		month = 1;
		year = 1970;
	}

	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	void setDate(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	static Date getCurrentDate()
	{
		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);
		int day = now.tm_mday;
		int month = now.tm_mon + 1;
		int year = now.tm_year + 1900;
		return Date(day, month, year);
	}


    friend bool operator<(const Date& d1, const Date& d2)
    {
        if (d1.year < d2.year) {
            return true;
        }
        else if (d1.year == d2.year) {
            if (d1.month < d2.month) {
                return true;
            }
            else if (d1.month == d2.month) {
                if (d1.day < d2.day) {
                    return true;
                }
            }
        }
        return false;
    }


};

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
    void push_head(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
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

    void pop_head(T& data) {
        if (!head) return;
        data = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
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


    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

class AddCourse {
private:
	std::string schoolYear, semester, courseID;
	Date startDate, endDate;
	bool writeData2File(); //return true if we write to file successfully
public:

	//Constructors
	AddCourse();
	AddCourse(const std::string& schoolYear, const std::string& semester, const std::string& courseID);
	AddCourse(const std::string& schoolYear, const std::string& semester, const std::string& courseID, const Date& startDate, const Date& endDate);


	//Function:

    //Check if we can enrolled in course
    bool checkValidEnroll();
	
	//create an empty course
	void createCourse(const std::string& schoolYear, const std::string& semester);

	//Get data from course
	std::string getID() const;
	Date getStartDate() const;
	Date getEndDate() const;
	
	//Load data from text file
	bool loadData(std::ifstream& fin);

	//Load dates of a course
	bool loadDates();
	
	


};