#include<iostream>
using namespace std;

/*Program for checking if entered string is a substring of previously entered string*/

int main()
{
	char a[10],b[10],ch;
	int i,j;
	cout<<"\nEnter string: ";
	cin>>a;
	do
	{
		cout<<"\nEnter substring: ";
		cin>>b;
		for(i=0;a[i]!='\0';i++)			/*loop for traversing super string*/
		{
			int k=i;
			for(j=0;b[j]!='\0';j++)		/*loop for traversing substring*/
			{
				if(a[k]!=b[j])
					break;
				k++;
			}
			if(b[j]=='\0')		/*if substring is present then above loop will terminate when b[j] becomes equal to '\0'*/
				break;		/*if substring present break from loop with current value of i*/
		}
		if(a[i]!='\0')	/*if substring is present then outer loop will terminate when a[i] is not equal to '\0'*/
			cout<<"\nSUBSTRING!!!!!";
		else
			cout<<"\nNOT SUBSTRING!!!";
		cout<<"\nContinue??[y/n]: ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');

	return 0;
}
