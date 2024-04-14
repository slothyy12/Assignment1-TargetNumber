/**	\file Target Number game
* \brief This is a game in which the user's goal is to turn all the values in the 3x3 grid to 9s.
* \details The game starts with an initial configuration of digits and the user’s target is to change all of them to 9 in the minimum number of
moves
* \author Tamanda Mdyanyama
* \date 12/04/2024
*/

#include <iostream>
using namespace std;

//Global constants
const int MAX = 3;
//class move
class Move{
public:
	int row,col;
	Move();
	void print();
};

//constructor
Move::Move() {
	int grid[MAX][MAX] = { 9 };
}

//Main function
int main() {
	Move moves;
	int choice ;

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
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		//No code needed
		break;
	default:
		cout << "Invalid choice, please try again " << endl;
	}


	return 0;
}