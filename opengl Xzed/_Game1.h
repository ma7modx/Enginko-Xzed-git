#pragma once 
#include <iostream>
#include "PartOfGamePlay.h"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include "Texture.h"
#include "Vector3.h"
#include "Vertex.h"
#include "ImmedientShapes.h"
#include "MColor.h"
#include "RenderingManager.h"
#include "Shader.h"
#include "GameController.h"
#include "GraphicsManager.h"
#include "GeometryVBO.h"
#include "MemoryManager.h"
#include "Mesh.h"
#include "ObjLoader.h"
//#include <SDL\SDL.h>
//#include <SDL\SDL_image.h>
using namespace std ;

class _Game1 : public PartOfGamePlay
{
public :
	//Model *m ; 
	Triangle *T;
	Mesh* mesh ;
	Shader *shader ;
	GeometryVBO*GPU ;
	Shader * sshader ;
	GeometryVBO* shaderGPU;
	unsigned int img;
	float r ;
	void Initialize()
	{
		IVertex& vref = VertexColor(Vector3(1) , MColor::Red) ;
		cout <<vref.GetSize()<<endl;
		IVertex v = VertexColor(Vector3(1) , MColor::Red) ;
		cout <<v.GetSize()<<endl;

		r = 0 ;

		mesh = new Mesh("mesh" , "bbn.obj");
		
		Vertex *V1, *V2,*V3 ;
		V1 = new VertexColor(Vector3(0,0,-7) , MColor::Blue ) ;
		V2 = new  VertexColor(Vector3(1,1,-7)  ,MColor::Black) ;
		V3 = new VertexColor(Vector3(-1,1,-7) ,MColor::Red) ;
		T = new Triangle(V1 , V2 , V3) ;

		IVertex *cc [3];
		cc[0]=  new Vertex( Vector3(0,22,-7)) ;cc[1] = new Vertex (Vector3(1,1,-7)) ;cc[2] = new Vertex(Vector3(-1,1,-7));

		VertexColor offset[3] = {VertexColor( Vector3(0,0,-7) , MColor(10,2,4)) ,VertexColor (Vector3(1,1,-7), MColor(10,200,4)) ,VertexColor(Vector3(-1,1,-7), MColor(10,2,200))}  ;

		GPU = new GeometryVBO(3 , offset) ;

		sshader = new Shader("mshader" , "vertex.vs","fragment.frag") ;
		
		VertexColor vc [4]={VertexColor( Vector3(-2,2,-90) , MColor(10,2,4)) ,VertexColor (Vector3(-2,-2,-90), MColor(10,200,4)) ,VertexColor(Vector3(2,-2,-90), MColor(10,2,200)) , VertexColor(Vector3(2,2,-90), MColor(10,2,200))};  
		shaderGPU= new GeometryVBO(4 , vc);

		glActiveTexture(GL_TEXTURE0);

		//  img=loadTexture("img.jpg");
	}
	void Update()
	{

	}
	
	void Draw()
	{
		// pass the camera matrix to the render manager


		sshader->Deactive();
		T->Debug();
		GPU->Draw();
		
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0,0,-7);
		glRotatef(r+= 0.3,1,0,0);
		mesh->Draw();
		glPopMatrix();

		sshader->Active();
	
		sshader->SetUniform("color" , Vector3(0.6,1,0.4)) ;

		int index1=sshader->GetAttribute("vertex");
		int index2=sshader->GetAttribute("inputcolor");
		
		int inde [] = {index1 , index2 } ;
		shaderGPU->Draw(2 , inde, Shapes::QUAD); 

	}
	bool Finished() 
	{
		bool ret = false ;
		if(ret)
			//delete m , T  ;
				delete T ;
		return ret ; 
	}

	/*
	unsigned int loadTexture(const char* name)
	{
	SDL_Surface* img=IMG_Load(name);
	SDL_PixelFormat form={NULL,32,4,0,0,0,0,8,8,8,8,0xff000000,0x00ff0000,0x0000ff00,0x000000ff,0,255};
	SDL_Surface* img2=SDL_ConvertSurface(img,&form,SDL_SWSURFACE);
	unsigned int texture;
	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D,texture);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img2->w,img2->h,0,GL_RGBA, GL_UNSIGNED_INT_8_8_8_8,img2->pixels);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	SDL_FreeSurface(img);
	SDL_FreeSurface(img2);
	return texture;
	}
	*/
};