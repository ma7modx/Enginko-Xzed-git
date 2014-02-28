#include "Vector2.h"

class InputDevice
{
public :
	int button ;
	virtual int GetBottunState(){}
	static int R , U , D , L , Up , Right , Down , Left ;
};

class StickInputDevice : public InputDevice
{
public :
	Vector2 thumbStick ;
	virtual Vector2 GetThumbStickState(){}
	static Vector2 StickUp , StickDown , StickRight, StickLeft;
};