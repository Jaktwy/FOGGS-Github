#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include "Structures.h"
#include "iostream"
#include <fstream>
#include <ostream>
#include <iosfwd>
#include <string>
#include "SceneObject.h"



class Cube : public SceneObject
{
private:
	GLfloat _rotation;
	Vector3 _position;
	/*bool Load(char* path);*/
	
public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	void Display();
	void DrawCubeArray();
	
	
};

