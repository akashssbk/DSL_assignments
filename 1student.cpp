#include<iostream>
using namespace std;

class DSA
{
	string name;
	static char status;
	int marks;
	static int sum,max,min,i,brr[31];
	public:
	DSA()
	{
		name="no_name";
		marks=-1;
		status='a';
		
	}
		
	void get()
	{
		cout<<"\nEnter Name of student: ";
		cin>>name;
		cout<<"\nEnter status [p/a]: ";
		cin>>status;
		if(status=='P' || status=='p')
		{
			i++;
			cout<<"\nEnter marks: ";
			cin>>marks;
			while(marks>30 || marks<0)
			{
				cout<<"\nWrong entry!! Enter marks again: ";
			        cin>>marks;
			}
			if(marks>max)
			{
				max=marks;
			}
			if(marks<min)
			{
				min=marks;
			}
			sum+=marks;
			brr[marks]++;
		}
	}

	void avg()
	{
		cout<<"\nAverage is: "<<sum/i;
	}

	void min_max()
	{
		cout<<"\nHigest score is: "<<max;
		cout<<"\nLowest score is: "<<min;

	}	
	
	void abs(DSA arr[5])
	{
		int j;
		cout<<"\n Absent students are";
		for(j=0;j<5;j++)
		{
			if(arr[j].marks==-1)
			{
				cout<<"\n"<<j+1<<"\t"<<arr[j].name;
			}
		}
		
	}
	
	void prs(DSA arr[5])
	{
		int j;
		cout<<"\n Present students are";
		for(j=0;j<5;j++)
		{
			if(arr[j].marks!=-1)
			{
				cout<<"\n"<<j+1<<"\t"<<arr[j].name;
			}
		}
		
	}

	void most()
	{
		int j,x,most;
		most=0;
		for(j=0;j<31;j++)
		{
			if(brr[j]>most)
			{
				most=brr[j];
			 	x=j;
			}
		}
		
		cout<<"\n"<<x<<" Marks are Scored by "<<brr[x]<<" students..";
	}
};
int DSA::sum;
char DSA::status;
int DSA::max;
int DSA::min=30;
int DSA::i;
int DSA::brr[31];

int main()
{
	DSA d[5];
	int i;
	for(i=0;i<5;i++)
	{
		d[i].get();
	}
	d[0].avg();
	d[0].min_max();
	d[0].abs(d);
	d[0].prs(d);
	d[0].most();
}


