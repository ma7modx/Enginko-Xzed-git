#pragma once
#include "ImmedientShapes.h"
#include "GraphicsManager.h"
#include "ModelHelpers.h"

class GeometryVBO :public Shape
{
public :
	GeometryVBO(int numOfVerices , IVertex vertex[]);
	void Edit(int start , int end , float arr[]){}
	void Transform(Matrix Transformation){}
	void Draw(){Draw(Shapes::TRIANGLE);}
	void Debug(){Draw(Shapes::LINE);} 
	void Draw(Shapes) ;
	void Draw(int numOfShaderAttributes , int shaderAttributesIndices[] , Shapes);
	void Draw(int numOfShaderAttributes , int shaderAttributesIndices[] );
	unsigned int GetNumOfVertices() { return numOfVertices ; }
	int GetBufferID() { return BufID ; } 
private :
	VertexData Mode;
	int vertexSize ;
	int numOfVertices;
	unsigned int BufID ; 
	void* Offsets[] ;
	void DetermineOffset(IVertex *v);
	

};