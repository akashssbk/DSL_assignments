#include<iostream>
using namespace std;

struct node
{
	int data;
	node *prev;
	node *next;
};

class dequeue
{
	node *nn;
	public:
	node *front,*rear;
	dequeue()
	{
		front = NULL;
		rear = NULL;
	}

	void insert_front()
	{
		nn=new node;
		cout<<"\nEnter data: ";
		cin>>nn->data;
		if(front!=NULL)
		{

			nn->next = front;
			nn->prev = NULL;
			front->prev = nn;
			front = nn;

		}

		else
		{

			nn->next = NULL;
			nn->prev = NULL;
			front = nn;
			rear = nn;

		}

	}


	void insert_rear()
	{
		nn=new node;
		cout<<"\nEnter data: ";
		cin>>nn->data;
		if(front!=NULL)
		{

			nn->next = NULL;
			nn->prev = rear;
			rear->next = nn;
			rear = nn;

		}

		else
		{

			nn->next = NULL;
			nn->prev = NULL;
			front = nn;
			rear = nn;

		}

	}


	void delete_front()
	{

		if(front!=NULL)
		{
			if(front==rear)
			{
				delete(front);
				front = NULL;
				rear = NULL;
			}

			else
			{
				front = front->next;
				delete(front->prev);
				front->prev = NULL;
			}
			cout<<"\nDeletion Successfull.!!";

		}

		else
		{

			cout<<"\nDequeue is Empty.!!";

		}

	}


	void delete_rear()
	{

		if(rear!=NULL)
		{
			if(front==rear)
			{
				delete(rear);
				front = NULL;
				rear = NULL;
			}

			else
			{
				rear = rear->prev;
				delete(rear->next);
				rear->next = NULL;
			}
			cout<<"\nDeletion Successfull.!!";

		}

		else
		{

			cout<<"\nDequeue is Empty.!!";

		}

	}

	void display()
	{
		node *cn=front;
		while(cn!=NULL)
		{
			cout<<"\n"<<cn->data;
			cn=cn->next;
		}
	}

};



int main()
{
	dequeue obj;

	int op;
	char ch;
	do
	{
		cout<<"\nEnter \n1 for Insert at front \n2 for Insert at rear \n3 for Delete at front \n4 for Delete at rear \n5 to display\n";
		cin>>op;
		switch(op)
		{
			case 1: obj.insert_front(); break;
			case 2: obj.insert_rear(); break;
			case 3: obj.delete_front(); break;
			case 4: obj.delete_rear(); break;
			case 5: obj.display(); break;
			default: cout<<"\nWrong option selected.!!";
		}
		cout<<"\nDo you want to Continue[y/n]: ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');

	return 0;
}
