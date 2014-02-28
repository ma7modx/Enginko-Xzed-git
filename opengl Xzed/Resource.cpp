#include "Resource.h"
#include "GameController.h"
#include "ResourceManager.h"
Resource::Resource(string name , Resource* Data)
{
	this->name = name ;
	GameController::GetGameController()->Resourcemanager->Register(name  , Data) ;
}
Resource::~Resource()
{
	if(name != "")
	GameController::GetGameController()->Resourcemanager->Delete(name) ;
}