//Andrii Bilyk

#include "CSquare.h"

#include <string>

using namespace std;

//constructor											setting up pointers 
CSquare::CSquare(int id, string name) : mCode(new int), mName(new string) { 


	SetID(id);

	SetName(name);

}

//destructor

CSquare::~CSquare()
{
	
	//deallocate memory by deleting operators

	delete mCode;
	
	delete mName;

}
