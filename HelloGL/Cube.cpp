#include <iostream>
#include "GLUTCallbacks.h"
#include "Cube.h"
#include "HelloGL.h"
#include "Structures.h"
#include <string>
#include "MeshLoader.h"
#include "SceneObject.h"
using namespace std;


Vertex* indexedVertices = nullptr; // v6,v7

Color* indexedColors = nullptr; //v6,v7

GLushort* indices = nullptr;    // back

int numVertices = 0;
int numColors = 0;
int numIndices = 0;






Cube::Cube(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	//glBegin(GL_TRIANGLES);
	//// face v0-v1-v2
	//glColor3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//glColor3f(1, 1, 0);
	//glVertex3f(-1, 1, 1);
	//glColor3f(1, 0, 0);
	//glVertex3f(-1, -1, 1);
	//// face v2-v3-v0
	//glColor3f(1, 0, 0);
	//glVertex3f(-1, -1, 1);
	//glColor3f(1, 0, 1);
	//glVertex3f(1, -1, 1);
	//glColor3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//// face v0-v3-v4
	//glColor3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//glColor3f(1, 0, 1);
	//glVertex3f(1, -1, 1);
	//glColor3f(0, 0, 1);
	//glVertex3f(1, -1, -1);
	//// face v4-v5-v0
	//glColor3f(0, 0, 1);
	//glVertex3f(1, -1, -1);
	//glColor3f(0, 1, 1);
	//glVertex3f(1, 1, -1);
	//glColor3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//// face v0-v5-v6
	//glColor3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//glColor3f(0, 1, 1);
	//glVertex3f(1, 1, -1);
	//glColor3f(0, 1, 0);
	//glVertex3f(-1, 1, -1);
	////face v6-v1-v0
	//glColor3f(0, 1, 0);
	//glVertex3f(-1, 1, -1);
	//glColor3f(1, 1, 0);
	//glVertex3f(-1, 1, 1);
	//glColor3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//// face v1-v6-v7
	//glColor3f(1, 1, 0);
	//glVertex3f(-1, 1, 1);
	//glColor3f(0, 1, 0);
	//glVertex3f(-1, 1, -1);
	//glColor3f(0, 0, 0);
	//glVertex3f(-1, -1, -1);
	//// face v7-v2-v1
	//glColor3f(0, 0, 0);
	//glVertex3f(-1, -1, -1);
	//glColor3f(1, 0, 0);
	//glVertex3f(-1, -1, 1);
	//glColor3f(1, 1, 0);
	//glVertex3f(-1, 1, 1);
	//// face v7-v4-v3
	//glColor3f(0, 0, 0);
	//glVertex3f(-1, -1, -1);
	//glColor3f(0, 0, 1);
	//glVertex3f(1, -1, -1);
	//glColor3f(1, 0, 1);
	//glVertex3f(1, -1, 1);
	//// face v3-v2-v7
	//glColor3f(1, 0, 1);
	//glVertex3f(1, -1, 1);
	//glColor3f(1, 0, 0);
	//glVertex3f(-1, -1, 1);
	//glColor3f(0, 0, 0);
	//glVertex3f(-1, -1, -1);
	//// face v4-v7-v6
	//glColor3f(0, 0, 1);
	//glVertex3f(1, -1, -1);
	//glColor3f(0, 0, 0);
	//glVertex3f(-1, -1, -1);
	//glColor3f(0, 1, 0);
	//glVertex3f(-1, 1, -1);
	//// face v6-v5-v4
	//glColor3f(0, 1, 0);
	//glVertex3f(-1, 1, -1);
	//glColor3f(0, 1, 1);
	//glVertex3f(1, 1, -1);
	//glColor3f(0, 0, 1);
	//glVertex3f(1, -1, -1);

	//glEnd();
	
	_position.x = x;
	_position.y = y;
	_position.z = z;
	/*Load((char*) "cube.txt");*/
	
	
	_rotation = 0.0f;
	
}



Cube::~Cube()
{
}

void Cube::Update()
{

	_rotation += ((rand() % 500) / 100.0f) - 2.5f;

	if (_position.z <= 42)
	{
		_position.z += 1.0f;
	}
	else
	{
		_position.z = -50.0f;
	}
}
	
	


//bool Cube::Load(char* path)
//{
//
//	ifstream inFile;
//	inFile.open(path);
//	if (!inFile.good())
//	{
//		std::cerr << "Can't open text file" << path << endl;
//		return false;
//	}
//
//	inFile >> numVertices;
//	indexedVertices = new Vertex[numVertices];
//	for (int i = 0; i < numVertices; i++)
//	{
//		inFile >> indexedVertices[i].x;
//		inFile >> indexedVertices[i].y;
//		inFile >> indexedVertices[i].z;
//	}
//
//	
//	inFile >> numIndices; 
//	indices = new GLushort[numIndices];
//	for (int i = 0; i < numIndices; i++)
//	{
//		inFile >> indices[i]; 
//	}
//	inFile.close();
//
//	return true;
//}

void Cube::Display()
{
	//glPushMatrix();
	//	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	//	glTranslatef(_position.x, _position.y, _position.z);
	//	glutWireCube(0.05);
	//glPopMatrix();

	

	/* glBegin(GL_POLYGON); //starts to draw a polygon
	glVertex2f(-0.75, 0.5); //define the first point of the polygon, top left
	glVertex2f(0.75, 0.5); //next point, top right
	glVertex2f(0.75, -0.5); //bottom right
	glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left
	glEnd(); //defines the end of the draw */

}


void Cube::DrawCubeArray()
{
	
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		
		glColor3fv(&_mesh->indexedColors[i].r);
		glVertex3fv(&_mesh->indexedVertices[i].x);

		
	}
	glEnd();
	glPopMatrix();
}

void Cube::Draw()
{

	if (_mesh->indexedVertices != nullptr && _mesh->indexedColors != nullptr && _mesh->indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->indexedVertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->indexedColors);

		glPushMatrix();
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glTranslatef(_position.x, _position.y, _position.z);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	
	
	/*
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
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
	*/




}






