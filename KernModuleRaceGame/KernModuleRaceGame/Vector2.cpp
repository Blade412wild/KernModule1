#include "Vector2.h"
#include <iostream>

//constructor
Vector2::Vector2(float _x, float _y) {
	X = _x;
	Y = _y;
}

//CopyConstructor
Vector2::Vector2(const Vector2& source) {
	std::cout << "Copy Constructor called" << std::endl;

	X = source.X;

	Y = source.Y;


}

//overloaded Assignment operator
Vector2& Vector2::operator=(const Vector2& source) {
	std::cout << "overloaded Assignment called" << std::endl;

	//Check for self assignment
	if (this == &source) {
		return *this;
	}

	X = source.X;

	Y = source.Y;

	return *this;

}

//Destructor
Vector2::~Vector2() {
	std::cout << "destructor called for this vector  @ this memory location " << this << std::endl;
}

float Vector2::Distance(Vector2 a, Vector2 b) {
	// _distance^2 = (x1 - x2)^2 + (y1 - y2)^2  
	float _distance = 0.0f;
	/*Circle1 = a;
	Circle2 = b;
	_distance = ((Circle1.X - Circle2.X) * (Circle1.X - Circle2.X)) + ((Circle1.Y - Circle2.Y) * (Circle1.Y - Circle2.Y));*/

	return _distance;
}



float Test(float a, float b) {
	float _answer;

	_answer = a + b;

	return _answer;
}


