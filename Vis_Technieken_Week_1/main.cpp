#include <GL/glew.h>
#include <GL/freeglut.h>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>

#include "Shader.h"
#include "Vertices.h"
#include "main.h"

#pragma comment(lib, "glew32.lib")

#ifdef WIN32
void GLAPIENTRY onDebug(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
#else
void onDebug(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam)
#endif
{
	std::cout << message << std::endl;
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1900, 1000);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Visualisatietechnieken");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(update);

	init();

	glutMainLoop();
}

void init()
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glClearColor(1, 0.7f, 0.3f, 1.0f);

	shader = new Shader("simple.vs", "simple.fs");
	shader->Use();
	modelViewUniform = glGetUniformLocation(shader->getProgramId(), "modelViewProjectionMatrix");	//haal de uniform van modelViewMatrix op

	glEnableVertexAttribArray(0);	// we gebruiken vertex attribute 0
	glEnableVertexAttribArray(1);	// en vertex attribute 1

	if (glDebugMessageCallback)
	{
		glDebugMessageCallback(&onDebug, NULL);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
		glEnable(GL_DEBUG_OUTPUT);
	}

	rotation = 0;
	lastTime = glutGet(GLUT_ELAPSED_TIME);
}

void update()
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	int elapsed = time - lastTime;

	rotation += elapsed / 1000.0f;

	glutPostRedisplay();
	lastTime = time;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 mvp = glm::perspective(80.0f, screenSize.x / (float)screenSize.y, 0.01f, 100.0f);		//begin met een perspective matrix
	mvp *= glm::lookAt(glm::vec3(0, 0, 2), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));					//vermenigvuldig met een lookat
	mvp = glm::translate(mvp, glm::vec3(0, 0, -1));													//of verplaats de camera gewoon naar achter
	mvp = glm::rotate(mvp, rotation, glm::vec3(2, 2, 0));											//roteer het object een beetje
	glUniformMatrix4fv(modelViewUniform, 1, 0, glm::value_ptr(mvp));								//en zet de matrix in opengl

	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(vertices[0]), vertices);					//geef aan dat de posities op deze locatie zitten
	glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(vertices[0]), ((float*)vertices) + 4);		//geef aan dat de kleuren op deze locatie zitten
	glDrawArrays(GL_TRIANGLES, 0, 36);																//en tekenen :)

	glutSwapBuffers();
}

void reshape(int newWidth, int newHeight)
{
	screenSize.x = newWidth;
	screenSize.y = newHeight;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == VK_ESCAPE)
		glutLeaveMainLoop();
}