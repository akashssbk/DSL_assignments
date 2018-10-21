#include<iostream>
#include<cstdio>
using namespace std;
		// structure for link list
struct node 
{
	char digit;		// Variable for storing bit
	struct node *next;	//pointer for pointing next node
	struct node *prev;	//pointer for pointing previous node
};

class binary
{
	struct node *nn;	// pointer to point newly created node
	public:
	struct node *header;
	char buffer[1024];	// for clering i/o buffer
	// header pointer 
		/* CONSTRUCTOR*/

	binary()	
	{
		header=NULL;
	}

	void get_num()
	{
		nn=new node;
		cout<<"\nEnter binary number: ";
		cin>>nn->digit;
		header=nn;
		nn->next=NULL;
		nn->prev=NULL;
		while(nn->digit!='\n' && (nn->digit=='0' || nn->digit=='1'))
		{
			nn=new node;
			nn->digit=cin.get();
			node* cn=header;
			while(cn->next!=NULL)
			{
				cn=cn->next;
			}
				cn->next=nn;
				nn->prev=cn;
				nn->next=NULL;
		}
		if((nn->digit!='0' && nn->digit!='1') && nn->digit!='\n')
		{
			cout<<"Entered number is not a binary!!";
			node *cn=header;
			header=NULL;
			while(cn->next!=NULL)
			{
				cn=cn->next;
				delete(cn->prev);
			}
			delete(cn);
		}
		else
		{
			nn->prev->next=NULL;
			delete(nn);
			cout<<"\nNUMBER ACCEPTED\n";
		}
		setvbuf(stdin, buffer, _IOFBF, 1024);			// for clering i/o buffer
	}
	
	
	void display()
	{
		node *cn=header;
		while(cn!=NULL)
		{
			cout<<cn->digit;
			cn=cn->next;
		}
		cout<<endl;
	}

	void one()
	{
		node *cn=header;
		while(cn!=NULL)
		{
			if(cn->digit=='1')
			cout<<"0";
			else
			cout<<"1";
			cn=cn->next;
		}
		cout<<endl;
	}

	void two()
	{
		node *cn=header;
		int i=1,j;
		while(cn->next!=NULL)
		{
			cn=cn->next;
			i++;
		}
		j=i;
		char arr[i];
		while(cn->digit=='0')
		{
			arr[i-1]=cn->digit;
			cn=cn->prev;
			i--;
		}
		arr[i-1]=cn->digit;
		cn=cn->prev;
		i--;
		while(cn!=NULL)
		{
			if(cn->digit=='1')
			arr[i-1]='0';
			else
			arr[i-1]='1';
			cn=cn->prev;
			i--;
		}
		cout<<endl;
		
		for(i=0;i<j;i++)
			cout<<arr[i];
	}

	void add(binary a)
	{
		binary b;
		b.get_num();
		int carry=0;
		nn=new node;
		header=nn;
		node *cn,*cn1,*cn2;
		cn=header;
		nn->prev=NULL;
		nn->next=NULL;
		cn1=a.header;
		cn2=b.header;
		while(cn1->next!=NULL)
			cn1=cn1->next;

		while(cn2->next!=NULL)
			cn2=cn2->next;

		while(cn1!=NULL && cn2!=NULL)		
		{
			int sum=(cn1->digit)+(cn2->digit)+carry;
			switch(sum)
			{
				case 96:	nn->digit='0'; carry=0; break;
				case 97:	nn->digit='1'; carry=0; break;
				case 98:	nn->digit='0'; carry=1; break;
				case 99:	nn->digit='1'; carry=1; break;

			}
			nn=new node;
			nn->prev=NULL;
			nn->next=header;
			header->prev=nn;
			header=nn;
			cn1=cn1->prev;
			cn2=cn2->prev;
		}

		if(carry==1)
		{
			while(cn1!=NULL)
			{
				int sum=(cn1->digit)+carry;
				switch(sum)
				{
					case 48:	nn->digit='0'; break;
					case 49:	nn->digit='1'; carry=0; break;
					case 50:	nn->digit='1'; carry=1; break;
				}
				nn=new node;
				nn->prev=NULL;
				nn->next=header;
				header->prev=nn;
				header=nn;
				cn1=cn1->prev;
			}

			
			while(cn2!=NULL)
			{
					int sum=(cn2->digit)+carry;
					switch(sum)
					{
						case 48:	nn->digit='0'; break;
						case 49:	nn->digit='1'; carry=0; break;
						case 50:	nn->digit='1'; carry=1; break;
					}
					nn=new node;
					nn->prev=NULL;
					nn->next=header;
					header->prev=nn;
					header=nn;
					cn2=cn2->prev;
			}
		}

		else
		{
			while(cn1!=NULL)
			{
				nn->digit=cn1->digit;
				nn=new node;
				nn->prev=NULL;
				nn->next=header;
				header->prev=nn;
				header=nn;
				cn1=cn1->prev;
			}
			while(cn2!=NULL)
			{
				nn->digit=cn2->digit;
				nn=new node;
				nn->prev=NULL;
				nn->next=header;
				header->prev=nn;
				header=nn;
				cn2=cn2->prev;
			}
		}
		delete(nn);
		cout<<"\nAddition of binary numbers is: ";
		this->display();
	}


};


int main()
{


	binary num,num1;	
	int y,yy=1;
	char div;
	while(yy==1)
	{
		cout<<"\nEnter \n1 to enter a binary number\n2 to display binary number \n3 to get 1's compliment \n4 to get 2's compliment ";
		cout<<"\n5 to add 2 binary numbers\n";
		cin>>y;
		switch(y)
		{
			case 1:	num.get_num();break;
			case 2: num.display();break;
			case 3: num.one();break;
			case 4: num.two();break;
			case 5: num1.add(num);break;
			default:cout<<"Wrong choice";
		}
		cout<<"\nEnter 1 to continue";
		cin>>yy;
		}
		
	return 0;
}
