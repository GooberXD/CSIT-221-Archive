#include "arraylist.hpp"
#include "list.hpp"
#include <iostream>
using namespace std;

int main() {
	List* list = new ArrayList();
	List* list2 = new ArrayList();
	list->add(2);
	list->add(4);
	list->add(6);
	list->add(8);
	list->add(10);
	list->add(96);
	list->add(50);
	list->add(20);
	list->add(10);
	list->add(96);
	list->add(50);
	list->add(20);
	list->add(10);
	list->add(96);
	list->add(50);
	list->add(20);
	list->add(10);
	list->add(96);
	list->add(50);
	list->add(20);
	list->print();
	return 0;
}
