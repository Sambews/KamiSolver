#include <iostream>
#include "Board.h"
using namespace std;

int main(){
	Triangle t(1, 2);
	cout << t.getColor() << " " << t.getOrientation() << '\n';

	string filename;
	cin >> filename;
	ifstream level(filename);

	Triangle* levelBoard[29][10];
	int parity = 1;
	string colline;

	for (int i = 0; i < 29; i++) { 

		getline(level, colline);
		for (int j = 0; j < 10; j++) {
			string col = colline.substr(0, 1);
			colline = colline.substr(2); //accounting for separator
			int color = stoi(col);
			levelBoard[i][j] = new Triangle(color, parity);
		}
		parity *= -1;
	}

	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 10; j++) {
			cout << levelBoard[i, j] << " ";
		}
		cout << endl;
	}
	
	Board board = new Board(levelBoard);
}
