#include <iostream>
#include <cmath>
#include "student.hpp"
#include "hidden.hpp"
using namespace std;
class Course {
	string topic;
	Student** students;
	int size;
	int capacity;

	public:
	Course(string topic) {
		students = hidden_init(topic, &this->topic, &size, &capacity);
	}

	void addStudent(Student* s) {
	    students = hidden_addStudent(s, &size, &capacity, students);
	}

	// TODO remove a Student
	string removeStudent(string name) {
	    int check = -1;
	    string courseCheck;
	    string noName;
	    
	    for(int i = 0; i < size ; i++){
	        if(students[i] && students[i]->name == name){
	            check = i;
	            courseCheck = students[i]->program;
	            break;
	        }
	        
	    }
	    
	    if(check == -1){
	        return "";
	    }
	    
	    
	    delete students[check];
	    for(int i = check; i < size - 1; i++){
	        students[i] = students[i + 1];          //shift
	    }
	    
	    students[size - 1] = nullptr;
	    size--;
	    
	    if(size <= (capacity * 2) / 3){
	        capacity -= floor(capacity * 0.25);
	        
	        if(capacity < 5){
	            capacity = 5;
	        }
	        
	        Student** arr = new Student*[capacity];
	        
	        for(int i = 0; i < capacity; i++){
                if(i < size){
                    arr[i] = students[i];
                }
                else{
                    arr[i] = nullptr;
                }
            }
	        
	        delete[] students;
	        students = arr;
	       
	        
	    }
	    
	    return courseCheck;
        
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