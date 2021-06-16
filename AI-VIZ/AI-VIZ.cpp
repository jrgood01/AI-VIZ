#include<GL/glut.h>
#include <iostream>
#include <string>

void main(int argc, char** argv) {
	// Main loop for OpenGL display
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("AI-VIZ");
	glutMainLoop();
}

