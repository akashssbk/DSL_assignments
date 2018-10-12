#include<iostream>
using namespace std;

class sort
{
	float a[20],b[20];
	int size;
	public:	
	sort()
	{
		size=0;
		
	}

	void get();
	void SelectionSORT();
	void BubbleSORT();
};


	void sort::get()
	{
		cout<<"\nEnter number of students: ";
		cin>>size;

		cout<<"\nEnter elements: ";
		for(int i=0;i<size; i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
	}

	void sort::SelectionSORT()
	{
		int i,j,min;
		float temp;
		for(i=0;i<size-1;i++)
		{
			min=i;
			for(j=i;j<size;j++)
			{
				if(a[j]<a[min])
					min=j;
			}
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}

		cout<<"\nAfter Selection Sort, Sorted elements are: \n";
		for(int i=0;i<size; i++)
			cout<<a[i]<<endl;

	}


	void sort::BubbleSORT()
	{
		int i,j;
		float temp;
		for(i=0;i<size;i++)
		{
			for(j=0;j<(size-i-1);j++)
			{
				if(b[j]>b[j+1])
				{
					temp=b[j];
					b[j]=b[j+1];
					b[j+1]=temp;
				}
			}

		}
		cout<<"\nAfter Bubble sort, Sorted elements are: \n";
		for(int k=0;k<size; k++)
			cout<<b[k]<<endl;
	}
};



int main()
{
	int n;
	sort number;

	cout<<"\nEnter number of students: ";
	cin>>n;
	float *p=new float[n];
	cout<<"\nEnter percentages:\n";
		for(int i=0;i<n;i++)
			cin>>p[i];
	number.quickSort(p,0,n-1);
	if(n>4)
	{
		cout<<"\nTop five scores are: ";
		for(int i=n-1;i>(n-6);i--)
		cout<<p[i]<<" ";
	}

	else
	{
		cout<<"\nTop score is: ";
		cout<<p[n-1];
	}


	return 0;
}
