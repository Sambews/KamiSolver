#include "Triangle.h"

Triangle::Triangle(){
	color = 0;
	orientation = 0;
	groupNum = 0;
	marked = false;
}

Triangle::Triangle(int o){
	color = 0;
	orientation = o;
	groupNum = 0;
	marked = false;

}

Triangle::Triangle(int c, int o){
	color = c;
	orientation = o;
	groupNum = 0;
	marked = false;

}

int Triangle::getColor(){
	return color;
}

void Triangle::setColor(int c){
	color = c;
}

int Triangle::getOrientation(){
	return orientation;
}

void Triangle::setOrientation(int o){
	orientation = o;
}

int Triangle::getGroupNum(){
	return groupNum;
}

void Triangle::setGroupNum(int g){
	groupNum = g;
}

bool Triangle::getMarked(){
	return marked;
}

void Triangle::setMarked(bool m){
	marked = m;
}
