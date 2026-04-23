#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Triangle.h"

class Board{
private:
	Triangle* boardArr[29][10];
	std::vector<std::vector<Triangle*>> groups;

public:
	Board();
	~Board();
	Board(Triangle* (&arr)[29][10]);
	
	Triangle* getElement(int, int);
	void setElement(Triangle*);
	
	void makeGroups();
	void makeGroupsH(int, int, int);
	void changeColor(int, int, int);
	
};

#endif
