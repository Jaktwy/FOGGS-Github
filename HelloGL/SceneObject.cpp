#include <iostream>
#include "GLUTCallbacks.h"
#include "Cube.h"
#include "HelloGL.h"
#include "Structures.h"
#include <string>
#include "MeshLoader.h"

SceneObject::SceneObject(Mesh* mesh)
{
	_mesh = mesh;
	
}

SceneObject::~SceneObject()
{
}

void SceneObject::Update()
{
	
}

void SceneObject::Draw()
{
}
