#include<iostream>

using namespace std;

/* This design pattern is used when object of a class wants to access some functionlity whose signature is unknown to it.
Then there is a class CAdapter which is concrete implementation of interface IAdapter that acts like an adapter between CClient and CAdaptee.

Think of it as the adapter for different power supplies:
Indian power style cable (CClient)
Universal Adapter (CAdapter)
German power supply sockets (CAdaptee)

This pattern is used to create wrappers.
Suppose CAdaptee is a library function which changes internally in terms of the signature, the client(user) does not have to worry about it.
This is because, the adapter class will adapt to the new changes keeping the interface (in this case request()) same to the client(user)
*/

class IAdapter{
public:
	virtual void request() const = 0;
};

class CAdaptee{
public:
	void specificRequest()
	{
		cout<<"Specific request has been called"<<endl;
	}
};

class CAdapter: public IAdapter{
CAdaptee* mAdaptee;                  //Concrete clas CAdapter has access to CAdaptee : look line 28
public:
	CAdapter(CAdaptee* adaptee)
	{
		mAdaptee = adaptee;
	}
	void request() const override
	{
		mAdaptee->specificRequest(); // mAdaptee is used to access the specificrequest
	}
};


class CClient{

	class IAdapter* mAdapter;
public:

	CClient(IAdapter* adapter)
	{
		mAdapter = adapter;
	}
	void execute()
	{
		mAdapter->request(); // Client only knows the interface request(), but it wants to access specificrequest() from CAdaptee. look line 20
	}
};

void ClientCode(const IAdapter *adapter) {
  adapter->request();
}
int main()
{
	CAdapter *adapter1 = new CAdapter(new CAdaptee());
	ClientCode(adapter1);
    // CClient client(adapter1);
    // client.execute();
}