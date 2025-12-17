// You are managing a Course Management System (Course MS).

// A course can contain a list of its students. 
// Your goal is to create the student array and make it dynamic.

// Start off with being able to accommodate 5 students, then when it gets full, 
// add 50% more capacity, rounded up. So from 5 students, it will become 8 
// (as half of 5 is 2.5, then rounded up to 3 additional slots), and so on.

#include <iostream>
#include "course.hpp"
using namespace std;

int main(int argc, char** argv) {
	Course* csit = new Course("CSIT221");
	char op;
	Student* s;
	while (true) {
		cout <<"Op: ";
		cin >> op;
		switch (op){
			case 'a':
				s = new Student;
				cout << "Name: ";
				cin >> s->name;
				cout << "Program and Year: ";
				cin >> s->program >> s->year;
				csit->addStudent(s);
				break;
			case 'p':
				csit->print();
				break;
			case 'x':
			    cout << "Exiting" << endl;
				return 0;
		}
	}
	return 0;
}