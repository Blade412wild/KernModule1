#pragma once
class Player
{
private:
	int width;
	int height;
	float alpha;

public:
	Player(int w, int h);
	void setAlpha(float a);
	float area();
	void draw();
};