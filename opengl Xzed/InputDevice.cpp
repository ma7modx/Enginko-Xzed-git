#include "InputDevice.h"

int InputDevice::U = 1 ;
int InputDevice::R = 2 ;
int InputDevice::L = 4 ;
int InputDevice::D = 8 ;
int InputDevice::Up = 16 ;
int InputDevice::Right = 32 ;
int InputDevice::Left = 64 ;
int InputDevice::Down = 128 ;


Vector2 StickInputDevice::StickUp = Vector2(0,1);
Vector2 StickInputDevice::StickRight = Vector2(1,0);
Vector2 StickInputDevice::StickDown = Vector2(0,-1);
Vector2 StickInputDevice::StickLeft = Vector2(-1,0);