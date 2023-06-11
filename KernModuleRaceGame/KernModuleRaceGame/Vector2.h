#pragma once
class Vector2
{
public:

	//Constructor
	Vector2(float x, float y);

	//copy Constructor
	Vector2(const Vector2& source);

	//Overloaded Assignment
	Vector2& operator=(const Vector2& source);

	//Destructor
	~Vector2();



	static float Distance(Vector2 a, Vector2 b);
	float Test(float a, float b);

private:
	float X;
	float Y;

	/*Vector2 Circle1;
	Vector2 Circle2;*/


};

