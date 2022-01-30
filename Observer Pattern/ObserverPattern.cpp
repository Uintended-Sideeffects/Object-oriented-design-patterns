#include<iostream>
#include <vector>
using namespace std;

/* This pattern is used when many different classes(DifferentDisplays) need to wait for some sort
 of notification from an Oversable class(WeatherStation). Notifination could be change in temperature(e.g).

 This pattern removes the need for polling. The listening classes need not always ask if there is a change.
*/


class IObserver{

public:
	virtual void update() = 0;
};


class IObservable{

public:
	virtual void add(IObserver *observer) = 0;
	virtual void notify() = 0;
};


class CWeatherStation : public IObservable{
    vector<IObserver*> mObserverList;
    int mTemp;
public:

	void add(IObserver *observer)
	{
		mObserverList.push_back(observer);
	}

	void notify()
	{
		
		for(auto it = mObserverList.begin(); it != mObserverList.end(); it++)
		{
 			(*it)->update();
		}
	}

	int getTemperature()
	{
		return mTemp;
	}

	void setTemperature(int temp)
	{
		mTemp = temp;
		notify();
	}

	void disp()
	{
		cout<<mTemp<<endl;
	}

};


class CPhoneDisplay: public IObserver{
    CWeatherStation* mStation;
public:

	CPhoneDisplay(CWeatherStation* station): mStation(station)
	{

	}

	void update()
	{ 
		cout<<"Inside Class Phone Display"<<endl;
    	cout<<"Temperature changed!!! - The new temperature is: " << mStation->getTemperature()<<endl;
	}

};

class CLcdDisplay: public IObserver{
    CWeatherStation* mStation;
public:

	CLcdDisplay(CWeatherStation* station): mStation(station)
	{

	}

	void update()
	{ 
		cout<<"Inside Class LCD Display"<<endl;
    	cout<<"Temperature changed!!! - The new temperature is: " << mStation->getTemperature()<<endl;
	}

};


int main()
{

CWeatherStation *WeatherStation1 = new CWeatherStation();
CPhoneDisplay *Display1 = new CPhoneDisplay(WeatherStation1);
WeatherStation1->add(Display1);
WeatherStation1->setTemperature(10);

}