#pragma once 
#include "MMath.h"
#include "GameObject.h"

class Camera : public GameObject
{
public :
	Camera(Vector3 Position , Vector3 eyeDirection)
	{
		this->Position  = Position ; this->eyeDirection = eyeDirection ; rotation = Vector2(0,0) ;
	}
	Matrix GetCameraMatrixLookAt()
	{
		return Matrix::LookAtDirection (Position , eyeDirection) ;
	}
	void MoveCameraPosition(Vector3 Position)
	{
		this->Position = Position ;
	}
	void MoveCameraDirection(Vector3 Direction)
	{
		this->eyeDirection = Direction ;
	}
protected :
Vector3 eyeDirection ;
Vector2 rotation ; //pitch arround the x  (up or down), yaw arround the y
virtual void LockCamera()
{
	if(rotation.GetPitch() > 90)
		rotation.SetPitch(90) ;
	if(rotation.GetPitch() < -90)
		rotation.SetPitch(90) ;
	if(rotation.GetYaw() > 360)
		rotation.SetPitch(rotation.GetYaw() - 360) ;
	if(rotation.GetYaw() < 0)
		rotation.SetPitch(rotation.GetYaw() + 360) ;
}
};