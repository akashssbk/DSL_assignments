#include<iostream>
using namespace std;

struct node
{
	char a;
	node *next;
};

class stk
{
	char stack[10];
	int top;
	public:
	stk()
	{
		top=-1;
	}

	int push(char x)
	{
		if(!stackFull())
		{
			top++;
			stack[top]=x;
			return 1;
		}

		else
		{
			cout<<"Expression is too long!!!";
			return 0;
		}
	}

	
	char pop()
	{
		if(!stackEmpty())
		{
			top--;
			return stack[top+1];
		}

		else
			return '\0';
	}

	int stackFull()
	{
		if(top==9)
			return 1;
		else
			return 0;
	}

	int stackEmpty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}

};

class exp
{
	
	stk s;
	node *nn;
	
	public:

	node *header;
	void newExp()
	{
		cout<<"\nEnter expression: ";
		nn= new node;
		cin>>nn->a;
		header=nn;
		nn->next=NULL;
		while(nn->a!='\n')
		{
			nn=new node;
			nn->a=cin.get();
			node *cn=header;
			while(cn->next!=NULL)
				cn=cn->next;
			nn->next=NULL;
			cn->next=nn;
		}
		delete(nn);
	}

	void check()
	{
		node *cn=header;
		while(cn!=NULL)
		{
			int p;
			if(cn->a=='(' || cn->a=='[' || cn->a=='{')
			{
				p=s.push(cn->a);
				if(!p)
				{
					break;
				}
				cn=cn->next;
			}

			else if(cn->a==')' || cn->a==']' || cn->a=='}')
			{
				char u;
				int t;
				u=s.pop();
				t=match(u,cn->a);
				if(!t)
				{
					break;
				}
				cn=cn->next;
			}
			else
				cn=cn->next;
		}
		
		if(cn==NULL && s.stackEmpty() )
			cout<<"\nExpression is well paranthesized.!!";
		
		else
			cout<<"\nExpression is not well paranthesized";

	}

	int match(char x,char y)
	{
		if(x=='(' && y==')')
			return 1;
		else if(x=='[' && y==']')
			return 1;

		else if(x=='{' && y=='}')
			return 1;
		return 0;
	}


};


int main()
{
	exp demo;
	char ch;
	do
	{
		demo.newExp();
		demo.check();
		cout<<"\nCheck more??[y/n]: ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	return 0;
}
