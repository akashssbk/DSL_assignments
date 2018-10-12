#include<iostream>
using namespace std;

class Cqueue
{
	struct pizza
	{
		int order[6],front,rear,size;
	}demo;
	public:
	Cqueue()
	{
		demo.size=6;
		demo.front=-1;
		demo.rear=-1;
	}

	int Qfull()
	{
		if(demo.front==(demo.rear+1)%demo.size)
			return 1;
		return 0;
	}

	int Qempty()
	{
		if(demo.front==-1)
			return 1;
		return 0;
	}

	int accept()
	{
		if(Qfull())
			cout<<"\nNo more orders can be placed!!";
		else
		{
			cout<<"\nEnter order number: ";
			if(demo.front==-1)
			{
				demo.front=0;
				demo.rear=0;
				cin>>demo.order[demo.rear];
				//cout<<"\n1\n";
			}
			else
			{
				demo.rear=(demo.rear+1)%demo.size;
				cin>>demo.order[demo.rear];
			}

		}
	}

	int ready()
	{
		if(Qempty())
			cout<<"\nNo orders are there!!";
		else
		{
			cout<<"\nReady order is: "<<demo.order[demo.front];
			if(demo.rear==demo.front)
			{
				demo.front=-1;
				demo.rear=-1;
			}
			else
			{
				demo.front=(demo.front+1)%demo.size;
			}

		}
	}

	int display()
	{
		int i=demo.front;
		while(i!=demo.rear)
		{
			cout<<endl<<demo.order[i];
			i=(i+1)%demo.size;
		}
		cout<<endl<<demo.order[i];
	}

};

int main()
{
	Cqueue q;
	int op;
	char ch;
	do
	{
		cout<<"Enter \n1 to new order\n2 for ready order \n3 for display order";
		cin>>op;
		switch(op)
		{
			case 1: q.accept(); break;
			case 2: q.ready(); break;
			case 3: q.display(); break;
			default: cout<<"\n Wrong choice";
		}
		cout<<"\nContinue[y/n]: ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	return 0;
}
