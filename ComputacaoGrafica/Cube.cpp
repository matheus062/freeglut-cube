#include "Cube.h"
// Constructor definition outside the class
Cube::Cube() {
}

void Cube::walkUp() {
	this->pos.y += this->speed;

	for (int i = 0; i < 8; i++) {
		this->vertices[i].y += this->speed;
	}
}

void Cube::walkDown() {
	this->pos.y -= this->speed;

	for (int i = 0; i < 8; i++) {
		this->vertices[i].y -= this->speed;
	}
}

void Cube::walkLeft() {
	this->pos.x -= this->speed;

	for (int i = 0; i < 8; i++) {
		this->vertices[i].x -= this->speed;
	}
}

void Cube::walkRight() {
	this->pos.x += this->speed;

	for (int i = 0; i < 8; i++) {
		this->vertices[i].x += this->speed;
	}
}

void Cube::walkFront() {
	this->pos.z -= this->speed;

	for (int i = 0; i < 8; i++) {
		this->vertices[i].z -= this->speed;
	}
}

void Cube::walkBack() {
	this->pos.z += this->speed;

	for (int i = 0; i < 8; i++) {
		this->vertices[i].z += this->speed;
	}
}

void Cube::scaleUp() {
	for (int i = 0; i < 8; i++) {
		float x = this->vertices[i].x - this->pos.x;
		float y = this->vertices[i].y - this->pos.y;
		float z = this->vertices[i].z - this->pos.z;

		this->vertices[i].x = (x * 1.1) + this->pos.x;
		this->vertices[i].y = (y * 1.1) + this->pos.y;
		this->vertices[i].z = (z * 1.1) + this->pos.z;
	}
}

void Cube::scaleDown() {
	for (int i = 0; i < 8; i++) {
		float x = this->vertices[i].x - this->pos.x;
		float y = this->vertices[i].y - this->pos.y;
		float z = this->vertices[i].z - this->pos.z;

		this->vertices[i].x = (x / 1.1) + this->pos.x;
		this->vertices[i].y = (y / 1.1) + this->pos.y;
		this->vertices[i].z = (z / 1.1) + this->pos.z;
	}
}

void Cube::rotateX(float angle) {
	float radian = angle * 3.1415926536 / 180.0;

	for (int i = 0; i < 8; i++) {
		float y = this->vertices[i].y - this->pos.y;
		float z = this->vertices[i].z - this->pos.z;

		this->vertices[i].y = this->pos.y + (y * cos(radian)) + (z * -sin(radian));
		this->vertices[i].z = this->pos.z + (y * sin(radian)) + (z * cos(radian));
	}
}

void Cube::rotateY(float angle) {
	float radian = angle * 3.1415926536 / 180.0;

	for (int i = 0; i < 8; i++) {
		float x = this->vertices[i].x - this->pos.x;
		float z = this->vertices[i].z - this->pos.z;
		this->vertices[i].x = this->pos.x + (x * cos(radian)) + (z * sin(radian));
		this->vertices[i].z = this->pos.z + (x * -sin(radian)) + (z * cos(radian));
	}
}

void Cube::rotateZ(float angle) {
	float radian = angle * 3.1415926536 / 180.0;

	for (int i = 0; i < 8; i++) {
		float x = this->vertices[i].x - this->pos.x;
		float y = this->vertices[i].y - this->pos.y;
		this->vertices[i].x = this->pos.x + (x * cos(radian)) + (y * sin(radian));
		this->vertices[i].y = this->pos.y + (x * -sin(radian)) + (y * cos(radian));
	}
}