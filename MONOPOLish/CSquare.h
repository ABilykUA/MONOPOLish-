#pragma once
//Andrii Bilyk

#include <string>


using namespace std;

class CSquare
{
public:


	//constructor											setting up pointers 
	CSquare(int id , string name);
	~CSquare();

	//functions 

	
	//getters and setters 
	void SetID(int input) { *mCode = input;}
	void SetName(string input) { *mName = input; }


	int GetID() { return *mCode; }
	string GetName() { return *mName; }


private:


	int *mCode;
	string *mName;


};


