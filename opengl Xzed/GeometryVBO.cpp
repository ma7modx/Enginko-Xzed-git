#include "GeometryVBO.h"
#include "GameController.h"


GeometryVBO::GeometryVBO(int numOfVerices , IVertex vertex[])
{
	this->numOfVertices = numOfVerices ;
	cout <<"Size Of Vertex : "<<vertex[0].GetSize()<<endl ;
	DetermineOffset(&vertex[0]) ;
	vertexSize =vertex[0].GetSize() ;
	Mode = vertex[0].GetData();	

	GameController::GetGameController()->Graphicsmanager->StoreInBuffer(BufID , vertex  ,numOfVerices*vertex[0].GetSize(), GPUDrawMode::STATIC);
}
void GeometryVBO::DetermineOffset(IVertex* v)
{
	for(int i = 0 ; i<10 ; ++i)
	{
		if(v->GetOffset(i) == -1)
			continue ;
		if(v->GetOffset(i) >= 0 )
			Offsets[i] = (void*)v->GetOffset(i);
		else 
			break ;
		if(v->GetOffset(i) == v->GetOffset(i+1))
			break ;
	}
}
void GeometryVBO::Draw(Shapes shapes = Shapes::TRIANGLE)
{
	GameController::GetGameController()->Graphicsmanager->BindBuffer(BufID) ;

	GameController::GetGameController()->Graphicsmanager->VBOModeDraw(numOfVertices,vertexSize, Offsets , Mode, shapes) ;

	GameController::GetGameController()->Graphicsmanager->BindBuffer(0) ;
}
void GeometryVBO::Draw(int numOfShaderAttributes , int shaderAttributesIndices[] , Shapes shapes = Shapes::TRIANGLE)
{
	GameController::GetGameController()->Graphicsmanager->BindBuffer(BufID) ;

	GameController::GetGameController()->Graphicsmanager->VBOShaderModeDraw(numOfVertices , numOfShaderAttributes , shaderAttributesIndices , vertexSize , Offsets , Mode , shapes);

	GameController::GetGameController()->Graphicsmanager->BindBuffer(0) ;
}
void GeometryVBO::Draw(int numOfShaderAttributes , int shaderAttributesIndices[] )
{
	Draw(numOfShaderAttributes ,shaderAttributesIndices , Shapes::TRIANGLE);
}
