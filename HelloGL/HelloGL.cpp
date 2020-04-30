#include "HelloGL.h"
#include "Cube.h"
#include <iostream>
#include "GLUTCallbacks.h"
#include "Cube.h"
#include "HelloGL.h"
#include "Structures.h"
#include <string>
#include "MeshLoader.h"
#include "SceneObject.h"
#include <ctime>





HelloGL::HelloGL(int argc, char* argv[])
{
	srand(time(NULL));
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();
	
	

	

	
	
	
}






HelloGL::~HelloGL(void)
{
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	
	//cycle through all of the cubes and call display
	for (int i = 0; i < 200; ++i)
	{
		objects[i]->Draw();
	}

	glFlush(); //flushes the scene drawn to the graphics card 
	glutSwapBuffers();
	
}

void HelloGL::DrawPolygon()
{

	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene

	glPushMatrix();
	/*	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
		glutWireCube(1.0f);
	glPopMatrix();*/

	glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f); //Adds Colour to the shape
		glVertex2f(-0.75, 0.5); //define the first point of the polygon, top left
		glVertex2f(0.75, 0.5); //Next point, top right 
		glVertex2f(0.75, -0.5); //bottom right
		glVertex2f(-0.75, 0.5); //last point of the polygon, bottom left
		glEnd(); //defines the end of the draw 
	}
	glPopMatrix();


	glFlush(); //flushes the scene drawn to the graphics card 

	glutSwapBuffers();
}


void HelloGL::Update()
{
	glLoadIdentity();
	
	//glutPostRedisplay();

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x,
		camera->center.y, camera->center.z, camera->up.x, camera->up.y,
		camera->up.z);
	
	for (int i = 0; i < 200; ++i)
	{
		objects[i]->Update();
	}
	
	if (rotation >= 360.0f)
		rotation = 0.0f;
	

	//Sleep(10);
	glutPostRedisplay();

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 0.5f;


	else if (key == 'a')
		rotation -= 0.5f;

	
	if (key == 'w')
		camera->eye.z += 0.1;

	else if (key == 's')
		camera->eye.x += 0.1;

	else if (key == 'x')
		camera->eye.y += 0.1;
}

void HelloGL::InitObjects()
{
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	rotation = 0.0f;
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 10.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	
	//Create an array of cubes
	for (int i = 0; i < 200; ++i)
	{
		//use random values to position the cubes in space
		objects[i] = new Cube(cubeMesh, ((rand() % 400) / 10.0f) - 20.f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//// Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	//// Set the correct perspective
	gluPerspective(45, 1, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}








