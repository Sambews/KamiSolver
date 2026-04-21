#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle{
private:
	int color;
	int orientation; //0 = pointing right, 1 = pointing left
	int groupNum;
	bool marked;
public:
	Triangle();
	Triangle(int);
	Triangle(int, int);

	int getColor();
	void setColor(int);
	int getOrientation();
	void setOrientation(int);
	int getGroupNum();
	void setGroupNum(int);
	bool getMarked();
	void setMarked(bool);
};
#endif
