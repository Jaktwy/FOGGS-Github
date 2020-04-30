#include "MeshLoader.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.numVertices;

		if (mesh.numVertices > 0)
		{
			mesh.indexedVertices = new Vertex[mesh.numVertices];

			for (int i = 0; i < mesh.numVertices; i++)
			{
				inFile >> mesh.indexedVertices[i].x;
				inFile >> mesh.indexedVertices[i].y;
				inFile >> mesh.indexedVertices[i].z;
			}
		}
	}

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.numColors;

		if(mesh.numColors > 0)
		{
			mesh.indexedColors = new Color[mesh.numColors];
			for (int i = 0; i < mesh.numColors; i++)
			{
				inFile >> mesh.indexedColors[i].r;
				inFile >> mesh.indexedColors[i].g;
				inFile >> mesh.indexedColors[i].b;
			}
		}
		
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.numIndices;

		if (mesh.numIndices > 0)
		{
			mesh.indices = new GLushort[mesh.numIndices];
			for (int i = 0; i < mesh.numIndices; i++)
			{
				inFile >> mesh.indices[i];
			}
		}
		
		
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadColours(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		inFile.close();

		return mesh;
	}
}