#pragma once
//Andrii Bilyk

#include <string>


using namespace std;

class CSquare
{
public:


	//constructor
	CSquare(int id , string name);

	//functions 

	
	//getters and setters 

	int GetID() { return mCode; }
	string GetName() { return mName; }


private:


	int mCode;
	string mName;


};


