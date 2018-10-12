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

	char top1()
	{
		if(!stackEmpty())
		{
			return stack[top];
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


class stk1
{
	int stack[10];
	int top;
	public:
	stk1()
	{
		top=-1;
	}

	int push(int x)
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

	
	int pop()
	{
		if(!stackEmpty())
		{
			top--;
			return stack[top+1];
		}

		else
			return '\0';
	}

	int top1()
	{
		if(!stackEmpty())
		{
			return stack[top];
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
	stk1 s1;
	node *nn;
	node *nn1;
	public:

	node *header;

	
	exp()
	{
	}
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
		node *pn=header;
		while(pn->next->a!='\n')
		{
			pn=pn->next;
		}
		pn->next=NULL;
		delete(nn);

	}


	void check()
	{
		node *cn=header;
		node *Header=NULL;
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
			}

			else if(cn->a=='+' || cn->a=='-' || cn->a=='*' || cn->a=='/')
			{
				char u;
				u=s.top1();
				if(priority(u)>=priority(cn->a))
				{
					u=s.pop();
					nn1=new node;
					nn1->a=u;

					if(Header!=NULL)
					{
						node *pn=Header;
						while(pn->next!=NULL)
							pn=pn->next;
						nn1->next=NULL;
						pn->next=nn1;
					}
					else
					{
						Header=nn1;
						nn1->next=NULL;
					}
					s.push(cn->a);

				}

				else
					s.push(cn->a);
			}

			else if(cn->a==')' || cn->a==']' || cn->a=='}')
			{
				
				char u;
				u=s.pop();
				while(!match(u,cn->a))
				{
					nn1=new node;
					nn1->a=u;
					if(Header!=NULL)
					{
						node *ln=Header;
						while(ln->next!=NULL)
							ln=ln->next;
						nn1->next=NULL;
						ln->next=nn1;
					}
					else
					{
						Header=nn1;
						nn1->next=NULL;
					}
					u=s.pop();
				}
			}
			
			else
			{
				nn1=new node;
				nn1->a=cn->a;

				if(Header==NULL)
				{
					nn1->next=NULL;
					Header=nn1;

				}
				else
				{

					node *pn=Header;
					while(pn->next!=NULL){
						pn=pn->next;
						}
					nn1->next=NULL;
					pn->next=nn1;

				}
			}
			cn=cn->next;
		}
		
		while(!s.stackEmpty())
		{
			char u=s.pop();
			nn1=new node;
			nn1->a=u;
			if(Header!=NULL)
			{
				node *ln=Header;
				while(ln->next!=NULL)
				ln=ln->next;
				nn1->next=NULL;
				ln->next=nn1;
			}
			else
			{
				Header=nn1;
				nn1->next=NULL;
			}
			
		}

		
		if(cn==NULL && s.stackEmpty())
			display(Header);
		
		else
			cout<<"\nExpression is not well paranthesized";
		
	}
	
	void eval()
	{
		node *cn=header;
		int ans;
		while(cn!=NULL)
		{
			if(cn->a=='+' || cn->a=='-' || cn->a=='*' || cn->a=='/')
			{
				switch(cn->a)
				{
					case '+': ans=s1.pop()+s1.pop(); s1.push(ans); break;
					case '-': ans=s1.pop()-s1.pop(); s1.push(-ans); break;
					case '*': ans=s1.pop()*s1.pop();s1.push(ans); break;				
					default:int n=s1.pop(); ans=s1.pop()/n; s1.push(ans);
				}
			}
			
			else
			{
				s1.push(cn->a-48);
				cout<<endl<<cn->a;
			}
			cn=cn->next;
		}

		cout<<"\nAns is: "<<(int)s1.pop();
		
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

	int priority(char y)
	{
		switch(y)
		{
			case '+': return 1;
			case '-': return 1;
			case '*': return 2;
			case '/': return 2;
			default: return 0;
		}
	}

	void display(node *cn)
	{
		while(cn!=NULL)
		{
			cout<<cn->a;
			cn=cn->next;
		}

	}


};


int main()
{
	int op;
	exp demo;
	char ch;
	do
	{
		demo.newExp();
		cout<<"\nEnter\n1)convert\n2)eval\n";
		cin>>op;
		if(op==1)
		demo.check();
		else if(op==2)
		demo.eval();
		else
		cout<<"\nWrong option\n";
		cout<<"\nConvert more??[y/n]: ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	return 0;
}
