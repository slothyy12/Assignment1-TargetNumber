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
#include <stack>
using namespace std;

//Global constants
const int MAX = 3;


//Classes
class Move{
	int grid[MAX][MAX];
public:
	int row =0 ,col=0;
	int counter = 0;
	Move();
	void print();
	void newGame(int const diff);
	void select();
	void undo();
	void redo();
	bool isSolved();
	
};

//Stack
stack <Move> undoStack;  //create an empty stack for storing each move
stack <Move> redoStack;	 //empty stack for storing each move that has been undone.

//constructor
Move::Move() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			grid[i][j] = 9;
		}
	}
}

void Move::print() {
	cout << " |0|1|2 "<<endl;
	for (int i = 0; i < MAX; i++) {
		cout << i << "|";
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
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
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
	Move temp;
	temp.row = row;
	temp.col = col;
	undoStack.push(temp);
	counter++;
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

void Move::undo() {
	Move temp;
	if (undoStack.empty()) {
		cout << "No moves to undo " << endl;
	}
	else {
		temp = undoStack.top();
		undoStack.pop();
		redoStack.push(temp);
		counter--;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (i == temp.row) {
					if (grid[i][j] == 0)
						grid[i][j] = 9;
					else
						grid[i][j]--;
				}
				else if (j == temp.col) {
					if (grid[i][j] == 0)
						grid[i][j] = 9;
					else grid[i][j]--;
				}
			}
		}
	}
}

void Move::redo() {
	Move temp;
	if (redoStack.empty()) {
		cout << " No moves to redo " << endl;
	}
	else {
		temp = redoStack.top();
		redoStack.pop();
		undoStack.push(temp);
		counter++;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (i == temp.row) {
					if (grid[i][j] == 9)
						grid[i][j] = 0;
					else
						grid[i][j]++;
				}
				else if (j == temp.col) {
					if (grid[i][j] == 9)
						grid[i][j] = 0;
					else grid[i][j]++;
				}
			}
		}
	}
	
  }

bool Move:: isSolved() {
	bool flag = true;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (grid[i][j] != 9)
				flag = false;
		}
	}
	return flag;
}

//Main function
int main() {
	srand(time(NULL));
	Move moves;		//object
	int difficulty = 3; // set to 9 as default beginner level
	int choice;

	moves.newGame(difficulty);
	do {
		moves.print();
		cout << "\nOptions" << endl;
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
			//@todo undo using stack
			moves.undo();
			
			break;
		case 3:
			//@todo redo using stack
			moves.redo();
			
			break;
		case 4:
			cout << "Please choose level of difficulty (9-1)-->" << endl;
			cin >> difficulty;

			moves.newGame(difficulty);
			while (!undoStack.empty()) {
				undoStack.pop();
			}

			while (!redoStack.empty()) {
				redoStack.pop();
			}

			break;
		case 5:
			//No code needed
			break;
		default:
			cout << "Invalid choice, please try again " << endl;
		}
	} while ((choice != 5) && (!moves.isSolved()));

	cout << "Congratulations, you have solved the game!!" << endl;
	cout << "You took " << moves.counter << " moves to complete" << endl;
	return 0;
}
