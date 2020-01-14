#include <iostream>
#include <fstream>

void createMaze();
bool mazeSolver(int, int);
void printMaze();
using namespace std;

int rows, columns, startRow, startCol;
char maze[35][35];
bool solved = false;

int main() {

	createMaze();
	mazeSolver(startRow, startCol);
	cout << endl;
	printMaze();
	return 0;
}

bool mazeSolver(int row, int column) {
	
	cout << row << " " << column;
	cout << endl;

	if (row < 0 || column < 0 || maze[row][column] == '+' || maze[row][column] == '#' || row > rows || column > columns) {
		return false;
	}

	if (maze[row][column] == 'E') {
		cout << "Maze Solved!";
		solved = true;
		return true;
	}

	while (!solved) {
		maze[row][column] = '#';
		if (mazeSolver(row, column - 1)) {
			return true;
		}
		if (mazeSolver(row + 1, column)) {
			return true;
		}
		if (mazeSolver(row, column + 1)) {
			return true;
		}
		if (mazeSolver(row - 1, column)) {
			return true;
		} 
		else {
			return false;
		}
	}
	
}

void createMaze() {

	ifstream inFile;
	inFile.open("maze.txt");

	inFile >> rows >> columns >> startRow >> startCol;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			inFile >> maze[i][j];
			if (maze[i][j] == 'S') {
				startRow = i;
				startCol = j;
			}
			cout << maze[i][j];
		}
		cout << endl;
	}
}

void printMaze() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << maze[i][j];
		}
		cout << endl; 
	}
}

