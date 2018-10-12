#include<iostream>
using namespace std;

class search
{

	public:
	int binary_search(int *a,int size,int x)
	{
		int low,mid,high;
		low=0;
		high=size-1;

		while(low<=high)
			{
				mid=(low+high)/2;
				if(a[mid]==x)
					return mid+1;
				else
				{
					if(a[mid]>x)
						high=mid-1;
					else
						low=mid+1;
				}
			}
		return 0;
	}

	int fibonacci_search(int *arr,int size,int x)
	{
		int *fb=new int[size];
		int a,b,f,i;
			
		fb[0]=0;
		fb[1]=1;
		for(i=2;i<size;i++)
			fb[i]=fb[i-1]+fb[i-2];
			
		f=size-1;
		for(i=0;fb[i]<size;i++);
		b=fb[i-1];
		a=fb[i-2];

		while(a>=0 && b>=1)
		{
			if(x<arr[f])
			{
				f=f-a;
				a=b-a;
				b=b-a;
			}

			else if(x>arr[f])
			{
				f=f+a;
				b=b-a;
				a=a-b;
			}
			
			else
				return f+1;
		}
		return 0;
	}

};

int main()
{
	int n,x,op,d;
	char ch;
	search number;

	cout<<"\nEnter number of students: ";
	cin>>n;
	int *p=new int[n];
	cout<<"\nEnter roll nos: ";
		for(int i=0;i<n;i++)
			cin>>p[i];
		do
		{
			cout<<"\nEnter roll no to search: ";
			cin>>x;
			cout<<"\nEnter \n1 for fibonacci search \n2 for Binary search\n";
			cin>>op;
			switch(op)
			{
				case 1: d=number.fibonacci_search(p,n,x);
						if(d)
							cout<<"\nRoll no "<<x<<" attained training program.. ";
						else
							cout<<"\nRoll no "<<x<<" did not attained training program.. ";
						break;
				case 2: d=number.binary_search(p,n,x);
						if(d)
							cout<<"\nRoll no "<<x<<" attained training program.. ";
						else
							cout<<"\nRoll no "<<x<<" did not attained training program.. ";
						break;
				default: cout<<"\nWrong ";
			}
			cout<<"\nSearch more?[y/n]: ";
			cin>>ch;
		}while(ch=='y' || ch=='Y');
	return 0;
}
