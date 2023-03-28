#include <iostream>
#include <vector>
#include <GL/freeglut.h>  
#include "Cube.h"

Cube cubo;

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Coloca a cor de background para preto e opaco
	glClearDepth(1.0f);                   // Define o buffer de profundidade para o mais distante possível
	glEnable(GL_DEPTH_TEST);   // Habilita o culling de profundidade
	glDepthFunc(GL_LEQUAL);    // Define o tipo de teste de profundidade
}

void redraw(int value) {
	glutPostRedisplay();
	glutTimerFunc(10, redraw, 0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.8f);

	int nextI = 0;

	for (int i = 0; i < 4; i++) {
		nextI = i + 1;

		if (nextI == 4) {
			nextI = 0;
		}


		glVertex3f(
			cubo.vertices[i].x,
			cubo.vertices[i].y,
			cubo.vertices[i].z
		);
		glVertex3f(
			cubo.vertices[nextI].x,
			cubo.vertices[nextI].y,
			cubo.vertices[nextI].z
		);

		glVertex3f(
			cubo.vertices[i + 4].x,
			cubo.vertices[i + 4].y,
			cubo.vertices[i + 4].z
		);
		glVertex3f(
			cubo.vertices[nextI + 4].x,
			cubo.vertices[nextI + 4].y,
			cubo.vertices[nextI + 4].z
		);
	}

	for (int i = 0; i < 4; i++) {
		nextI = i + 4;
		glVertex3f(
			cubo.vertices[i].x,
			cubo.vertices[i].y,
			cubo.vertices[i].z
		);
		glVertex3f(
			cubo.vertices[nextI].x,
			cubo.vertices[nextI].y,
			cubo.vertices[nextI].z
		);
	}

	glEnd();

	glutSwapBuffers();
}


//Função de redesenhou prioriza o aspecto da projeção
void reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, aspect, 0.1f, 500.0f);
}

void keyboard(unsigned char key, int x, int y) {
	std::cout << key;
	switch (key) {
	case 27:
		exit(0);
		break;
	case 'w':
	case 'W':	// 87
		cubo.walkUp();
		break;
	case 's':
	case 'S':	// 83
		cubo.walkDown();
		break;
	case 'd':
	case 'D':	// 68
		cubo.walkRight();
		break;
	case 'a':
	case 'A':	// 65
		cubo.walkLeft();
		break;
	case 'e':
	case 'E':	// 69
		cubo.walkFront();
		break;
	case 'q':
	case 'Q':	// 81
		cubo.walkBack();
		break;
	case '2':
		cubo.rotateX(-3.0);
		break;
	case '8':
		cubo.rotateX(3.0);
		break;
	case '6':
		cubo.rotateY(3.0);
		break;
	case '4':
		cubo.rotateY(-3.0);
		break;
	case '9':
		cubo.rotateZ(3.0);
		break;
	case '7':
		cubo.rotateZ(-3.0);
		break;
	case 'z':
	case 'Z':
		cubo.scaleDown();
		break;
	case 'x':
	case 'X':
		cubo.scaleUp();
		break;
	}
}

void keyboard_special(int key, int x, int y) {
	std::cout << key;
	switch (key) {

	}
}

int main(int argc, char** argv) {
	cubo.pos.x = 25.0;
	cubo.pos.y = 0.0;
	cubo.pos.z = -75.0;

	cubo.vertices.push_back(Vertice(0.0, 25.0, -100.0));
	cubo.vertices.push_back(Vertice(50.0, 25.0, -100.0));
	cubo.vertices.push_back(Vertice(50.0, -25.0, -100.0));
	cubo.vertices.push_back(Vertice(0.0, -25.0, -100.0));

	cubo.vertices.push_back(Vertice(0.0, 25.0, -50.0));
	cubo.vertices.push_back(Vertice(50.0, 25.0, -50.0));
	cubo.vertices.push_back(Vertice(50.0, -25.0, -50.0));
	cubo.vertices.push_back(Vertice(0.0, -25.0, -50.0));

	cubo.speed = 1;

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(800, 500);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Cubo");

	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard_special);
	glutTimerFunc(10, redraw, 0);
	glutReshapeFunc(reshape);
	initGL();
	glutMainLoop();

	return 0;
}