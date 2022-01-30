#include<iostream>

using namespace std;



/*Algorithm (IBehavior) has the ability to be independent from the client meaning:
-> There could be different types of behaviors (Remember : The duck example)
-> This design pattern motivates to not use inheritance to make specialized classes, rather have interface class for the beahaviors, 
   and have special behaviors*/

/*
 -> The Strategy pattern lets you indirectly alter the object’s behavior at runtime by associating it with different sub-objects which
    can perform specific sub-tasks in different ways.
 -> Use the Strategy when you have a lot of similar classes that only differ in the way they execute some behavior.
 -> Use the pattern to isolate the business logic of a class from the implementation details of algorithms that may not be as important
    in the context of that logic.
 -> Use the pattern when your class has a massive conditional operator that switches between different variants of the same algorithm
 */
class IBehavior
{
public:
	virtual void display() = 0;
};

class BehaviorA : public IBehavior
{
public:
	void display()
	{
		cout<<"Display Behavior A"<<endl;
	}
};

class BehaviorB : public IBehavior
{
public:
	void display()
	{
		cout<<"Display Behavior B"<<endl;
	}
};

class CClient{

	IBehavior *behavior;
public:
    CClient(IBehavior *behavior): behavior(behavior){}
    ~CClient()
    {
    	delete behavior;
    }

    void displayBehavior()
    {
    	behavior->display();
    }
};



int main()
{
	CClient clientA(new BehaviorA);
	clientA.displayBehavior();
}