#pragma once
#include <vector>
#include <GL/freeglut.h>  

struct Vertice {
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat z = 0.0;

	Vertice() {};
	Vertice(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}
};

class Cube
{
public:
	Vertice pos;
	std::vector<Vertice> vertices;
	GLint edges[12][2] = { {0,1}, {1,2}, {2,3}, {3,0}, {4,5}, {5,6}, {6,7}, {7,4}, {0,4}, {1,5}, {2,6}, {3,7} };

	int speed;
	float size;

	void walkUp();
	void walkDown();
	void walkLeft();
	void walkRight();
	void walkFront();
	void walkBack();
	void scaleUp();
	void scaleDown();
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	Cube();
};

