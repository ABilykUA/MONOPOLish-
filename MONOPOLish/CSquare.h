//Andrii Bilyk


#include <string>
#include <string>

using namespace std;

// TODO --- finish seting up the CSquare class and array.

class CSquare
{



public:

	CSquare(char id , string name);

	//getters and setters 

	char GetID() { return mCode; }
	string GetName() { return mName; }


private:

	char mCode;

	string mName;


};


