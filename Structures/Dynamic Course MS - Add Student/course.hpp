#include <iostream>
#include <cmath>
#include "student.hpp"
using namespace std;
class Course {
	string topic;
	Student** students;
	int size;
	int capacity;

	public:
	// TODO constructor
	Course(string topic) {
        this->topic = topic;
        capacity = 5;
        size = 0;
        students = new Student*[capacity];
        
        for(int i = 0; i < capacity; i++){
            students[i] = nullptr;
        }
	}

	// TODO add student
	void addStudent(Student* s) {
        if(size >= capacity){
            int inc = ceil(capacity * 0.5); //50%
            int newCap = capacity + inc;
            
            Student** arr = new Student*[newCap];
            
            for(int i = 0; i < newCap; i++){
                if(i < size){
                    arr[i] = students[i];
                }
                else{
                    arr[i] = nullptr;
                }
            }
                
            delete[] students;
            students = arr;
            capacity = newCap;
                
        }
            
        students[size++] = s;
    }
	

	// DO NOT MODIFY
	void print() {
		cout << "Title: "<< topic << endl;
		cout << "Student size: " << size << "/" << capacity << endl;
		for (int i = 0; i < capacity; i++) {
			if (i >= size) {
				cout << i+1<< ". (none)" << endl;
			} else {
			    Student* s = students[i];
				cout << i+1 << ". " << s->name << " (" << s->program << " " << s->year << ")" << endl;
			}
		}
	}
};