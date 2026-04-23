#include "Board.h"

Board::Board(){
	for(int i = 0; i < 29; i++){
		for(int j = 0; j < 10; j++){
			boardArr[i][j] = new Triangle();	
		}
	}
}

Board::Board(Triangle* [29][10] arr) {
	boardArr = arr;
}

Board::~Board(){
	for(int i = 0; i < 29; i++){
		for(int j = 0; j < 10; j++){
			delete boardArr[i][j];
		}
	}
}

//Classify the groups
void Board::makeGroups(){
	//Unmark every triangle
	for(int i = 0; i < 29; i++){
		for(int j = 0; i < 10; j++){
			boardArr[i][j]->setMarked(false);
		}
	}
	
	//If an unmarked triangle is found, create a new group, begin recursively adding triangles to it. Group num corresponds to index of group
	for(int i = 0; i < 29; i++){
		for(int j = 0; j < 10; j++){
			if(!boardArr[i][j]->getMarked()){
				groups.push_back(std::vector<Triangle*>());
				makeGroupsH(i, j, groups.size()-1);
			}
		}
	}
}

void Board::makeGroupsH(int i, int j, int n){
	//Mark triangle, add it to the group, recursively call on unmarked adjacent triangles of same color.
	Triangle* t = boardArr[i][j];
	t->setMarked(true);
	t->setGroupNum(n);
	groups.back().push_back(t);
	
	if(i != 0){
		if((boardArr[i-1][j]->getColor() == t->getColor()) && !boardArr[i-1][j]->getMarked())
			makeGroupsH(i-1, j, n);
	}

	if(i != 28){
		if((boardArr[i+1][j]->getColor() == t->getColor()) && !boardArr[i+1][j]->getMarked())
			makeGroupsH(i+1, j, n);
	}
	
	if(j != 0){
		if(t->getOrientation() == 0){
			if((boardArr[i][j-1]->getColor() == t->getColor()) && !boardArr[i][j-1]->getMarked())
				makeGroupsH(i, j-1, n);
		}
	}
	else if( j != 9){
		if(t->getOrientation() == 1){
			if((boardArr[i][j+1]->getColor() == t->getColor()) && !boardArr[i][j+1]->getMarked())
				makeGroupsH(i, j+1, n);
		}
	}
}


void Board::changeColor(int i, int j, int c){
	Triangle* t = boardArr[i][j];
	
	if(t->getColor() == c)
		return;

	for(Triangle* t : groups.at(t->getGroupNum())){
		t->setColor(c);
	}
	
	//IDEALLY INSTEAD OF CALLING MAKEGROUPS IT CHECKS GROUPS ADJACENT TO THIS GROUP AND MERGES WITH ONES OF SAME COLOR.
	makeGroups();
}

