// You are managing a Course Management System (Course MS).

// A course can contain a list of its students. 
// After having been able to add students, your new goal is to be able 
// to remove students from the list.

// If the inputted name does not exist in the list, return an empty string "" instead.

// Note that when the students list have reached 2/3 of its capacity, 
// trim down the capacity of the list by 25% rounded down.

// Also note that when deleting a struct (or any object created using malloc, calloc, or new), 
// you must deallocate their memory once you've had no use of them. 

#include <iostream>
#include "course.hpp"
using namespace std;

int main(int argc, char** argv) {
	Course* csit = new Course("CSIT221");
	char op;
	Student* s;
	string res;
	string name;
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
			case 'r':
			    cout << "Who to remove? ";
			    cin >> name;
			    res = csit->removeStudent(name);
			    if (res != "") {
			        cout << "Removed student from " << res << endl;
			    } else {
			        cout << "No name " << name << " in list" << endl;
			    }
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