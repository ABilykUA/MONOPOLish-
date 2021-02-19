#include <string>

using namespace std;

class CPlayer
{

public:

	//constructor
	CPlayer(string name, int money , int position);


	//functions 

	void AddPosition(int add);

	void AddMoney(int add);

	void SubtractMoney(int subtract);

	void PassGo();

	void CheckIfGoIsPassed();


	//getters & setters 

	string GetName() { return mName; }

	int GetMoney() { return mMoney; }

	int GetPosition() { return mPosition; }
	
	

private:

	string mName;

	int mMoney;

	int mPosition;




};

