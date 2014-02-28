#include "ResourceManager.h"
#include <iostream>
using namespace std ;
 void ResourceManager::Register(string name , Resource* resource)
	{
		if(Resources.find(name) == Resources.end())
		Resources[name] = resource; // should save orginal data not pointer on it
		else 
		cout << "This Resource name already exist : " << name <<endl;
	}

 Resource* ResourceManager::Get(string name)
	{
		if(Resources.find(name) != Resources.end())
			return Resources[name] ;
		cout << "This Resource name is not exist : " << name <<endl;
	}
 // Load Resource 
 void ResourceManager::Delete(string name)
	{
		Resources.erase(name) ;
	}
	