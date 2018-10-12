#include<iostream>
using namespace std;

class sort
{

	public:
	int partition(int arr[],int low,int high)
	{
		int pivot = arr[high];
		int i = low-1;
		for(int j=low;j<high;j++)
			{
				if(arr[j]<=pivot)
				{
					i++;
					swap(&arr[i],&arr[j]);
				}
			}
		swap(&arr[i+1],&arr[high]);
		return (i+1);
	}

	void quickSort(int arr[],int low,int high)
	{
		if(low<high)
		{
			int pi = partition(arr,low,high);
			quickSort(arr,low,pi-1);
			quickSort(arr,pi+1,high);
		}
	}

	void swap(int *a, int *b)
	{
		int temp=*a;
		*a=*b;
		*b=temp;
	}

};

int main()
{
	int n;
	sort number;

	cout<<"\nEnter number of elements in array";
	cin>>n;
	int *p=new int[n];
	cout<<"\nEnter elements";
		for(int i=0;i<n;i++)
			cin>>p[i];
			number.quickSort(p,0,n-1);
			cout<<"\nSorted array is: ";
			for(int i=0;i<n;i++)
			cout<<p[i]<<" ";

	return 0;
}
