#include <bits/stdc++.h>
#include "point.hpp"
#include "scoreboard.hpp"

using namespace std;

int main(){
//	for point.hpp
//	Point p1, p2;
//	
//	printf("Enter x and y for point 1: ");
//	scanf("%d %d", &p1.x, &p1.y);
//	
//	printf("Enter x and y for point 2: ");
//	scanf("%d %d", &p2.x, &p2.y);
//	
//	Point midRes = p1.midpoint(&p2);
//	
//	printf("P1: %d, %d\n", p1.x, p1.y);	
//	printf("P2: %d, %d\n", p2.x, p2.y);	
//	
//	cout << "Midpoint: " << midRes.x << ", " << midRes.y << endl;
	
	
	
//	for entry.hpp

    Entry e;
	char op;
	Scoreboard* board = new Scoreboard();
	
	do{
		cout << "Op: ";
		cin >> op;
		
		switch(op){
			
			case 'a':
				cout << "Enter name: ";
				cin.ignore();
				getline(cin, e.name);
				cout << "Enter country: ";
				cin >> e.country;
				cout << "Enter score: ";
				cin >> e.score;
				board->add(e); 
				break;
			
			case 'p':
//				cout << "Name: " << e.name << endl;
//				cout << "Country: " << e.country << endl;
//				cout << "Score: " << e.score << endl;
				board->print();
				break;	
		}
		
	}while (op != 'x');
	
	return 0;
	
}
