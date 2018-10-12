#include<iostream>
using namespace std;
		// structure for link list
struct node 
{
	char status;		// Variable for storing status of seat
	struct node *next;	//pointer for pointing next node
	struct node *prev;	//pointer for pointing previous node
};

class cinema
{
	struct node *nn;	// pointer to point newly created node
	public:
	struct node *header;	// header pointer 
		/* CONSTRUCTOR*/
/* Here we have created all the 7 seats using linklist for respective object of class*/
	cinema()	
	{
	/*creating first node*/
		header=NULL;
		nn=new node;
		nn->status='A';
		nn->prev=nn;
		nn->next=nn;
		header=nn;
		int i=1;
	/*creating remaining nodes*/
		while(i<7)
		{
		
		nn=new node;
		nn->status='A';
		nn->prev=header->prev;
		nn->next=header;
		header->prev->next=nn;
		header->prev=nn;
		header=nn;		
		i++;
		}
	}
	/*book function.. It accepts column number as parameter*/
	void book(int k)
	{
		node *cn=header;
		int l=1;
	/*traverse till respective column is reached*/
		while(l<k)
		{
			cn=cn->next;
			l++;
		}
		if(cn->status=='A')
		{
			cn->status='B';
			cout<<"\nCongrats, Mentioned seat is booked for you...!!";
		}
		else
		{
			cout<<"\nSorry, Mentioned seat is already booked by someone else...!!";
		}
	}
	
	
	/*cancel function.. It accepts column number as parameter*/
	void cancel(int k)
	{
		node *cn=header;
		int l=1;
	/*traverse till respective column is reached*/
		while(l<k)
		{
			cn=cn->next;
			l++;
		}
		if(cn->status=='B')
		{
			cn->status='A';
			cout<<"\nDone, Your booking is canceled...!!";
		}
		else
		{
			cout<<"\nSorry, Mentioned seat was not booked...!!";
		}
	}

/*
	void display(int k)
	{
		node *cn=header;
		int l=1;
		while(cn!=header || l==1)
		{
			if(cn->status=='A')
			{
				cout<<"\t"<<k<<" , "<<l;
			}
			else
			{
				cout<<"\t "<<"    ";
			}
			cn=cn->next;
			l++;
		}
		cout<<endl;
	}

*/

	/*display function.. It accepts column number as parameter*/
	void display(int k)
	{
		node *cn=header;
		int l=1;
		cout<<k;
	/*traverse till end of respective row and check status and display*/
		while(cn!=header || l==1)
		{
			cout<<"\t"<<cn->status;
			cn=cn->next;
			l++;
		}
		cout<<endl;
	}
};


int main()
{


	cinema seats[10];	//10 objects representing rows
	int y,yy=1,row,col;
	char div;
	while(yy==1)
	{
		cout<<"\nEnter \n1 to see available seats list,\n2 to book a seat, \n3 to cancel a booking";
		cin>>y;
		switch(y)
		{
			case 1: for(int i=1;i<8;i++)
				{
					cout<<"\t"<<i;
				}
				cout<<"\n";
				for(int i=0;i<10;i++)
				{
					seats[i].display(i+1);
				}
				break;
			case 2: cout<<"\nEnter row";
				cin>>row;
				while(row>10 || row<1)
				{
					cout<<"\nOnly 1-10 rows are available.., Please enter row again:";
					cin>>row;
				}
				cout<<"\nEnter column";
				cin>>col;
				while(col>7 || col<1)
				{
					cout<<"\nOnly 1-7 columns are available.., Please enter column again:";
					cin>>col;
				}
				seats[row-1].book(col); break;
			case 3:cout<<"\nEnter row";
				cin>>row;
				while(row>10 || row<1)
				{
					cout<<"\nOnly 1-10 rows are available.., Please enter row again:";
					cin>>row;
				}
				cout<<"\nEnter column";
				cin>>col;
				while(col>7 || col<1)
				{
					cout<<"\nOnly 1-7 columns are available.., Please enter column again:";
					cin>>col;
				}
				seats[row-1].cancel(col);	break;
			default:cout<<"Wrong choice";
		}
		cout<<"\nEnter 1 to continue";
		cin>>yy;
		}
		
	return 0;
}
