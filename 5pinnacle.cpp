#include<iostream>
using namespace std;
#include<string.h>
		// structure for link list
struct node 
{
	string name;
	long prn;
	struct node *next;	//pointer for pointing next node
};

class Pinnacle_Club
{
	struct node *nn;
	public:
	struct node *header;
	Pinnacle_Club()	//Creating president and Secretory in constructor
	{
		nn= new node;
		header=nn;
		nn->name="AKASH";
		nn->prn=0;
		//nn->next=NULL;
		nn=new node;
		header->next=nn;
		nn->name="Atharva";
		nn->prn=00;
		nn->next=NULL;
	}

	void new_member()
	{
		nn=new node;
		cout<<"\nEnter name: ";
		cin>>nn->name;
		cout<<"\nEnter PRN number: ";
		cin>>nn->prn;
		nn->next=NULL;		
		struct node *cn=header;
		while(cn->next->next!=NULL)
		{
			cn=cn->next;
		}
		nn->next=cn->next;
		cn->next=nn;
	}
	
	void remove_member()
	{
		nn=new node;
		cout<<"\nEnter name of member to delete : ";
		cin>>nn->name;
		cout<<"\nEnter PRN number of member to delete : ";
		cin>>nn->prn;		
		struct node *cn=header;
		while(cn->next!=NULL)
		{
			if(cn->next->name==nn->name && cn->next->prn==nn->prn)
			{
				struct node *temp=cn->next;
				cn->next=cn->next->next;
				delete(temp);
				break;
			}
			cn=cn->next;
		}
		if(cn->next!=NULL)
			cout<<"\nMember deleted Successfully!!!";

		else
			cout<<"\nMember doesn't exist with given info!!!";

	}

	void display()
	{
		struct node *cn=header;
		cout<<endl;
		cout<<endl<<"President is "<<cn->name;
		cn=cn->next;
		cout<<"\nMembers are: ";
		while(cn->next!=NULL)
		{
			cout<<endl<<cn->name<<"\t"<<cn->prn;
			cn=cn->next;
		}
		cout<<endl<<"Secretory is "<<cn->name;
	}

	void count()
	{
		int i=0;
		node *cn=header->next;
		while(cn->next!=NULL)
		{
			i++;
			cn=cn->next;
		}
		cout<<"\nTotal number of members are "<<i;
	}

	void cng_prs(Pinnacle_Club *d)
	{
		cout<<"\nEnter name of new PRESIDENT : ";
		cin>>header->name;
		d->header->name=header->name;
		cout<<"\nPresident changed successfully";
	}

	void cng_src(Pinnacle_Club *d)
	{
		struct node *cn=header;
		struct node *pn;
		while(cn->next!=NULL)
		{
			cn=cn->next;
		}
		cout<<"\nEnter name of new SECRETORY : ";
		cin>>cn->name;
		pn=d->header;
		while(pn->next!=NULL)
		{
			pn=pn->next;
		}
		pn->name=cn->name;
		cout<<"\nSecretory changed successfully";
		
	}

	void reverslist(node *cn)
	{
		if(cn->next!=NULL)
		{
			reverslist(cn->next);
		}
			cout<<endl<<cn->name<<"\t"<<cn->prn;
	}

	void cnt(Pinnacle_Club c, Pinnacle_Club d)
	{
		struct node *cn=c.header;
		struct node *pn=header;
		header->name=cn->name;
		cn=cn->next;
		nn=new node;
		header->next=nn;
		while(cn->next!=NULL)
		{
			while(pn->next!=NULL)
			{
				pn=pn->next;
			}
			pn->name=cn->name;
			pn->prn=cn->prn;
			pn->next=NULL;
			nn=new node;
			nn->next=NULL;
			pn->next=nn;
			cn=cn->next;
		}
		pn->next->name=d.header->next->name;
		pn=pn->next;
		nn=new node;
		pn->next=nn;
		nn->next=NULL;
		cn=d.header->next->next;
		while(cn!=NULL)
		{
			while(pn->next!=NULL)
			{
				pn=pn->next;
			}
			pn->name=cn->name;
			pn->prn=cn->prn;
			pn->next=NULL;
			nn=new node;
			nn->next=NULL;
			pn->next=nn;
			cn=cn->next;
		}
		delete(nn);
		pn->next=NULL;
		cout<<"\nLists concatinated successfully";
		
		this->display();
	}

};



int main()
{


	Pinnacle_Club memberA,memberB,memberC;
	int y,yy=1;
	char div;
	while(yy==1)
	{
		cout<<"\nEnter \n1 for new member registration,\n2 for remove a member, \n3 for display all members,\n4 for change president ";
		cout<<"\n5 for change secretory, \n6 to display reverse list, \n7 to concatiante both divisions, \n8 to count total number of members:\n";
		cin>>y;
		switch(y)
		{
			case 1: cout<<"\nEnter division";
				cin>>div;
				if(div=='A' || div=='a')
				{	memberA.new_member();}
				else if(div=='B' || div=='b')
				{	memberB.new_member();}
				else
				cout<<"\nWrong division selected...!";break;
			case 2: cout<<"\nEnter division";
				cin>>div;
				if(div=='A' || div=='a')
				{	memberA.remove_member();} 
				else if(div=='B' || div=='b')
				{	memberB.remove_member();}
				else
				cout<<"\nWrong division selected...!";break;
			case 3:cout<<"\nEnter division";
				cin>>div;
				if(div=='A' || div=='a')
				{	memberA.display();}
				else if(div=='B' || div=='b')
				{	memberB.display();}
				else
				cout<<"\nWrong division selected...!";break;			
			case 4:memberA.cng_prs(&memberB); break;
			case 5:memberA.cng_src(&memberB); break;
			case 6:cout<<"\nEnter division";
				cin>>div;
				if(div=='A' || div=='a')
				{	cout<<endl<<endl<<"REVERSE LIST: "<<endl; memberA.reverslist(memberA.header); break;}
				else if(div=='B' || div=='b')
				{	cout<<endl<<endl<<"REVERSE LIST: "<<endl; memberB.reverslist(memberB.header); break;}
				else
				cout<<"\nWrong division selected...!";break;
			case 8:cout<<"\nEnter division";
				cin>>div;
				if(div=='A' || div=='a')
				{	memberA.count();}
				else if(div=='B' || div=='b')
				{	memberB.count();}
				else
				cout<<"\nWrong division selected...!";break;
			case 7:/*memberC=memberA; */ memberC.cnt(memberA, memberB); break;
			default:cout<<"Wrong choice";
		}
		cout<<"\nEnter 1 to continue";
		cin>>yy;
		}
		
	return 0;
}
