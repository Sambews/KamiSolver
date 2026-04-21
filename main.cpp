#include <iostream>
#include "Triangle.h"

int main(){
	Triangle t(1, 2);
	std::cout << t.getColor() << " " << t.getOrientation() << '\n';
}
