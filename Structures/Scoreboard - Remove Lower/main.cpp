// You decided as an arbiter to disqualify low scores as you deem 
// it undesirable to be added to the scoreboard.

// Your task is to implement int removeLower(int score) that will remove 
// the entries bearing a score lower than the given score. 
// You are to return an integer representing the number of entries removed by this action.

#include <iostream>
#include "board.hpp"
using namespace std;

int main() {
	entry player1;
	Scoreboard* board = new Scoreboard();
    char ans;
    int score;
	do {
		cout << "Op: ";
		cin >> ans;
        switch (ans) {
            case 'a':
        		cout << "Enter name: ";
                cin.ignore();
        		getline(cin, player1.name);
        		cout << "Enter college: ";
        		cin >> player1.college;
        		cout << "Enter score: ";
        		cin >> player1.score;
        		board->add(player1);
                break;
            case 'l':
                cout << "Enter score baseline: ";
                cin >> score;
                cout << "Number of entries removed: " << board->removeLower(score) << endl;
                break;
            case 'p':
                board->print();
                break;
            case 'x':
                cout << "Exiting";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
	} while (ans != 'x');

	return 0;
}