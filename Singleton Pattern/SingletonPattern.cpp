#include<iostream>

using namespace std;
/* This designn patterns aims to restrict more than one object of a class. There should NOT be more than one instance of a class.
	This is achieved by making the constructor of the class private and createing a static pointer to the class as the member.
	Then a static function is declared which initializes the private static attribute and returns it to the requester*/

class CSingleton{
	static CSingleton * mInstance;
	int mData;
	CSingleton(){
		mData = 0;
	}

public:
	static CSingleton* getInstance();

	int getData()
	{
		return mData;
	}


	void setData(int data)
	{
		mData = data;
	}
};

CSingleton* CSingleton::mInstance = nullptr;

CSingleton* CSingleton::getInstance()
{
	if(mInstance == nullptr)
	{
		mInstance = new CSingleton;
	}
	return mInstance;
}

int main(int argc, char const *argv[])
{
	CSingleton* object = CSingleton::getInstance();
	object->setData(10);
	cout<< object -> getData();

	return 0;
}