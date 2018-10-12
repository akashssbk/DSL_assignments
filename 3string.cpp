#include<iostream>
#include<string.h>
using namespace std;

class str
{
	char  s1[20],s2[20];
	int l1,l2;
	public:
/*
	str()
	{
		s1="";
		s2="";


	}*/
	
	void get()
	{
		cout<<"\nEnter name: ";
		cin>>s1;
		cout<<"\nEnter name: ";
		cin>>s2;
	}
	
	void len()
	{
		l1=0;
		l2=0;
		for(int z=0;s1[z]!='\0';z++)
		{
			l1++;
		}

		for(int z=0;s2[z]!='\0';z++)
		{
			l2++;
		}
		
		cout<<"\nLength of first string is "<<l1<<", Length of second string is "<<l2;
	}

	void copy()
	{
		int i;
		cout<<"\nEnter string to be copied: ";
		cin>>i;
		if(i==1)
		{
			int z;
			for(z=0;s1[z]!='\0';z++)
			{
				s2[z]=s1[z];
			}
			s2[z]='\0';

			cout<<"\n Copied 1st into 2nd, result is "<<s2;
		}
		else if(i==2)
		{
			int z;
			for(z=0;s2[z]!='\0';z++)
			{
				s1[z]=s2[z];
			}
			s1[z]='\0';
			cout<<"\n Copied 2nd into 1st, result is "<<s1;
		}
		else
		{
			cout<<"\n Wrong entry!!!!!";
		}
	}

	void cmp()
	{
		l1=0;
		l2=0;
		int z;
		for(z=0;s1[z]!='\0';z++)
		{
			l1++;
		}

		for(z=0;s2[z]!='\0';z++)
		{
			l2++;
		}
		z++;
		if(l1==l2)
		{		
			for(z=0;z<l1;z++)
			{
				if(s1[z]!=s2[z])
					{break;}
			}	
		}
/*		else
		{
			
		}

*/		if(z==l2)
		cout<<"\nString equal";
		else
		cout<<"\nString not equal";
	}

	void cnt()
	{
		int i,j;
		cout<<"\nEnter string to be concatinated: ";
		cin>>i;
		if(i==1)
		{
			int z;
			for(z=0;s2[z]!='\0';z++);
			for(int j=0;s1[j]!='\0';j++,z++)
			{
				s2[z]=s1[j];
			}
			s2[z]='\0';

			cout<<"\n concatinated 1st into 2nd, result is "<<s2;
		}
		else if(i==2)
		{
			int z;
			for(z=0;s1[z]!='\0';z++);
			for(int j=0;s2[j]!='\0';j++,z++)
			{
				s1[z]=s2[j];
			}
			s1[z]='\0';

			cout<<"\n concatinated 2nd into 1st, result is "<<s1;
		}
		else
		{
			cout<<"\n Wrong entry!!!!!";
		}
	}

	void rev()
	{
		int i,j;
		cout<<"\nEnter string to be reversed: ";
		cin>>i;
		if(i==1)
		{
			int z;
			char s3[20];
			for(z=0;s1[z]!='\0';z++);
			for(j=z-1;j>=0;j--)
			{
				s3[(z-1)-j]=s1[j];
			}
			s3[z]='\0';
			for(j=0;s3[j]!='\0';j++)
			{
				s1[j]=s3[j];
			}

			cout<<"\n Reversed 1st string, result is "<<s1;
		}
		else if(i==2)
		{
			int z;
			char s3[20];
			for(z=0;s2[z]!='\0';z++);
			for(j=z-1;j>=0;j--)
			{
				s3[(z-1)-j]=s2[j];
			}
			s3[z]='\0';
			for(j=0;s3[j]!='\0';j++)
			{
				s2[j]=s3[j];
			}

			cout<<"\n Reversed 1st string, result is "<<s2;
		}
		else
		{
			cout<<"\n Wrong entry!!!!!";
		}
	}

	void frq()
	{
		int i,j,k;
		cout<<"\nEnter string number whos frequency you want to count: ";
		cin>>i;
		if(i==1)
		{
			int s3[20],z;
			for(z=0;z<20;z++)
			{
				s3[z]=0;
			}
			for(z=0;s1[z]!='\0';z++)
			{
				for(j=0;j<z;j++)
				{
					if(s1[j]==s1[z])
					{
						s3[j]++;
						s3[z]=-1;
						break;
						cout<<"\n Eureka";
					}					
				}
				
				if(s3[z]==0)
					s3[z]++;

			}
			cout<<"\n Frequency counted, result is ";

			for(z=0;s1[z]!='\0';z++)
			{	
				if(s3[z]!=-1)
				{
					cout<<"\n"<<s1[z]<<" "<<s3[z];
				}

			}

		}
		else if(i==2)
		{
			int s3[20],z;
			for(z=0;z<20;z++)
			{
				s3[z]=0;
			}
			for(z=0;s2[z]!='\0';z++)
			{
				for(j=0;j<z;j++)
				{
					if(s2[j]==s2[z])
					{
						s3[j]++;
						s3[z]=-1;
						break;
					}					
				}
				
				if(s3[z]==0)
					s3[z]++;

			}
			cout<<"\n Frequency counted, result is ";

			for(z=0;s2[z]!='\0';z++)
			{	
				if(s3[z]!=-1)
				{
					cout<<"\n"<<s2[z]<<" : "<<s3[z];
				}

			}

		}
		else
		{
			cout<<"\n Wrong entry!!!!!";
		}
	}

};



int main()
{
	str j;
	int k,g;
	do
	{
		cout<<"\nEnter 1 to enter new string, 2 for length calculation, 3 for copy string, 4 for compare string, 5 for concatinate string, 6 for reverse a string "; 
		cin>>k;
		switch(k)
		{
			case 1: j.get(); break;
			case 2: j.len(); break;
			case 3: j.copy(); break;
			case 4: j.cmp(); break;
			case 5: j.cnt(); break;
			case 6: j.rev(); break;
			case 7: j.frq(); break;
			default : cout<<"\nWrong choice!!!!!!!!"; break;
		}
		cout<<"\nEnter 1 to continue";
		cin>>g;
	}while(g==1);	

	return 0;
}
