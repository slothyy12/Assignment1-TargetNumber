/**	\file Target Number game
* \brief This is a game in which the user's goal is to turn all the values in the 3x3 grid to 9s.
* \details The game starts with an initial configuration of digits and the user’s target is to change all of them to 9 in the minimum number of
moves
* \author Tamanda Mdyanyama
* \date 12/04/2024
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global constants
const int MAX = 3;


//Classes
class Move{
	int grid[MAX][MAX];
public:
	int row =0 ,col=0;
	Move();
	void print();
	void newGame(int const diff);
	void select();

};

//constructor
Move::Move() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			grid[i][j] = 9;
		}
	}
}

void Move::print() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << grid[i][j] << ",";
		}
		cout << endl;
	 }
}

void Move::newGame(int const diff) {
	for (int z = 0; z < diff; z++) {
		row = rand() % 2;
		col = rand() % 2;
		for (int i = 0; i < diff; i++) {
			for (int j = 0; j < diff; j++) {
				if (i == row) {
					if (grid[i][j] == 0)
						grid[i][j] = 9;
					else
						grid[i][j]--;
				}
				else if (j == col) {
					if (grid[i][j] == 0)
						grid[i][j] = 9;
					else grid[i][j]--;
				}
			}
		}
	}
	
	
}

void Move:: select() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i == row) {
				if (grid[i][j] == 9)
					grid[i][j] = 0;
				else
					grid[i][j]++;
			}
			else if (j == col) {
				if (grid[i][j] == 9)
					grid[i][j] = 0;
				else grid[i][j]++;
			}
		}
	}
}


//Main function
int main() {
	srand(time(NULL));
	Move moves;
	int difficulty = 9; // set to 9 as default beginner level
	int choice;

	moves.newGame(difficulty);
	do {
		moves.print();
		cout << "Options" << endl;
		cout << "1. Select a cell " << endl;
		cout << "2. Undo " << endl;
		cout << "3. Redo " << endl;
		cout << "4. New Game " << endl;
		cout << "5. Quit " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Please enter row and column (0 based) " << endl;
			cin >> moves.row >> moves.col;

			moves.select();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << "Please choose level of difficulty (9-1)-->" << endl;
			cin >> difficulty;

			moves.newGame(difficulty);
			break;
		case 5:
			//No code needed
			break;
		default:
			cout << "Invalid choice, please try again " << endl;
		}
	} while (choice != 5);

	return 0;
}
