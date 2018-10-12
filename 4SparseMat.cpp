#include<iostream>
using namespace std;
int k=0;

class sparse
{
	int arr[5][5],M1[25][3];
	public:
	
	void accept()
	{
		cout<<"\nEnter elements of a 5*5 matrix";		
		int i,j;k=0;
		for(i=0;i<5;i++)	
		{
			for(j=0;j<5;j++)	
			{
				cin>>arr[i][j];
				if(arr[i][j]!=0)
				k++;
			}
		}
		//cout<<endl;
	}
	
	void display()
	{
		cout<<endl<<"\nEntered matrix is :"<<endl;		
		int i,j;
		for(i=0;i<5;i++)	
		{
			for(j=0;j<5;j++)	
			{
				cout<<arr[i][j]<<"\t";
			}
			cout<<endl;
		}
		
	}
	
	void Sparse()
	{
		M1[0][0]=5;
		M1[0][1]=5;
		M1[0][2]=k;
		int i,j,n=1;
		for(i=0;i<5 && n<=k;i++)	
		{
			for(j=0;j<5;j++)	
			{
				if(arr[i][j]!=0)
				{
					M1[n][0]=i;
					M1[n][1]=j;
					M1[n][2]=arr[i][j];
					n++;
				}
			}
		}

		cout<<endl<<"\nIts sparse matrix is :"<<endl;

		for(i=0;i<=k;i++)	
		{
			cout<<endl<<M1[i][0];
			cout<<"\t"<<M1[i][1];
			cout<<"\t"<<M1[i][2];
		}
	}

	void transpose()
	{
		int i=0,j=0;
		int n=1;
		int M1ts[k+1][3];
		M1ts[0][0]=5;
		M1ts[0][1]=5;
		M1ts[0][2]=k;
	
		for(i=0;i<5 && n<=k;i++)	
		{
			for(j=1;j<=k;j++)	
			{
				if(M1[j][1]==i)
				{
					M1ts[n][0]=i;
					M1ts[n][1]=M1[j][0];
					M1ts[n][2]=M1[j][2];
					n++;
				}
			}
		}
	
		cout<<endl<<"\nIts Transpose matrix is :"<<endl;
		for(i=0;i<=k;i++)	
		{
			cout<<endl<<M1ts[i][0];
			cout<<"\t"<<M1ts[i][1];
			cout<<"\t"<<M1ts[i][2];
		}
	
	}

	void Ftranspose()
	{
		int M1tf [k+1][3],i,j;
		M1tf[0][0]=5;
		M1tf[0][1]=5;
		M1tf[0][2]=k;
	
		int rterms[5],rpos[5];
		
	
		for(i=0;i<5;i++)
		rterms[i]=0;
		
		for(i=0;i<=k;i++)
		rterms[M1[i][1]]++;
		
		rpos[0]=1;
		
		for(i=1;i<5;i++)
		rpos[i]=rterms[i-1]+rpos[i-1];
	
		for(i=1;i<=k;i++)
		{
			int o=rpos[M1[i][1]];
			M1tf[o][0]=M1[i][1];
			M1tf[o][1]=M1[i][0];
			M1tf[o][2]=M1[i][2];
			rpos[M1[i][1]]++;
		}
	
		cout<<endl<<"\nIts Transpose matrix is(FAST) :"<<endl;
		for(i=0;i<=k;i++)	
		{
			cout<<endl<<M1tf[i][0];
			cout<<"\t"<<M1tf[i][1];
			cout<<"\t"<<M1tf[i][2];
		}


	}

	void add()
	{
		sparse ss;
		cout<<"\nFor addition enter second matrix :";
		ss.accept();
		ss.Sparse();
		if(M1[0][0]==ss.M1[0][0] && M1[0][1]==ss.M1[0][1])
		{
			int i=1,j=1,k=1;
			int adrr[M1[0][2]+ss.M1[0][2]][3];
			adrr[0][0]=M1[0][0];
			adrr[0][1]=M1[0][1];
			while(i<=M1[0][2] && j<=ss.M1[0][2])
			{
				if(M1[i][0]==ss.M1[j][0])
				{
					if(M1[i][1]==ss.M1[j][1])
					{
						adrr[k][0]=M1[i][0];
						adrr[k][1]=M1[i][1];
						adrr[k][2]=M1[i][2]+ss.M1[j][2];
						i++;j++;k++;
					}
	
					else
					{
						if(M1[i][1]<ss.M1[j][1])
						{
							adrr[k][0]=M1[i][0];
							adrr[k][1]=M1[i][1];
							adrr[k][2]=M1[i][2];
							i++;k++;
						}
		
						else
						{
							adrr[k][0]=ss.M1[j][0];
							adrr[k][1]=ss.M1[j][1];
							adrr[k][2]=ss.M1[j][2];
							j++;k++;
						}
					}
				}
				
				else
				{
					if(M1[i][0]<ss.M1[j][0])
					{
						adrr[k][0]=M1[i][0];
						adrr[k][1]=M1[i][1];
						adrr[k][2]=M1[i][2];
						i++;k++;
					}	
					else
					{
						adrr[k][0]=ss.M1[j][0];
						adrr[k][1]=ss.M1[j][1];
						adrr[k][2]=ss.M1[j][2];
						j++;k++;
					}
				}			
			}
	
			while(i<=M1[0][2])
			{
				adrr[k][0]=M1[i][0];
				adrr[k][1]=M1[i][1];
				adrr[k][2]=M1[i][2];
				i++;k++;
			}
	
			while(j<=ss.M1[0][2])
			{
				adrr[k][0]=ss.M1[j][0];
				adrr[k][1]=ss.M1[j][1];
				adrr[k][2]=ss.M1[j][2];
				j++;k++;
			}
	
			adrr[0][2]=k-1;
			cout<<endl<<"\nAddition matrix is :"<<endl;
			for(i=0;i<=k-1;i++)	
			{
				cout<<endl<<adrr[i][0];
				cout<<"\t"<<adrr[i][1];
				cout<<"\t"<<adrr[i][2];
			}
	
	
		}
	
		else
		{
			cout<<"\nAddition not possible";
		}

		
	}

};







int main()
{
	int i=1,j;

	sparse s;
	while(i)
	{
		cout<<"\nEnter 1 to enter a 5*5 matrix \n2 to display matrix \n3 to get sparse matrix \n4 to get simple transpose"; 
		cout<<"\n5 to get fast transpose \n6 to add two sparse matrix..";
		cin>>j;
		switch(j)
		{
			case 1:s.accept();break; 
			case 2:s.display();break;
			case 3:s.Sparse();break;
			case 4:s.transpose();break;
			case 5:s.Ftranspose();break;
			case 6:s.add();break;
			default: cout<<"\nWrong option choosen!!!";
		}
		cout<<"\nPress 0 to exit, else press any other key....";
		cin>>i;
	}
	return 0;	
}
