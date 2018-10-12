#include<iostream>
using namespace std;
int w=10;
		class CrickMinton
		{
			string name;								//varable to store name
			char crick,minton;							//variables to store if they paly any of the 													game
			static int i,j,k;							//variables for counting students who play/dont 												play any game

			public:
				void get_info()							//Function to accept info
				{
					cout<<"\nEnter name of student";
					cin>>name;
					cout<<"\nEnter Y/y if plays cricket, else enter any other key";
					cin>>crick;
					if(crick=='Y' || crick=='y')		// counting number of students playing cricket
					{
						i++;
					}
					cout<<"\nEnter Y/y if plays badminton, else enter any other key";
					cin>>minton;
					if(minton=='Y' || minton=='y')		// counting number of students playing badminton
					{
						j++;
					}
					else if(crick!='Y' && crick!='y')	// counting number of students not playing any game
					{
						k++;
					}
				}

				void C_U_B(CrickMinton tt[10])		// Function for list of students playing either game
				{
					int o;
					cout<<endl<<w-k<<" students play either of the game";
					for(o=0;o<w;o++)
					{
						if(tt[o].crick=='Y' || tt[o].crick=='y' || tt[o].minton=='Y' || tt[o].minton=='y')
						{
							cout<<endl<<tt[o].name;
						}
					}
				}

				void C_n_B(CrickMinton tt[10])		// Function for list of students playing both game
				{
					int o;
					cout<<endl<<i+j-(w-k)<<" students play both of the game";
					for(o=0;o<w;o++)
					{
						if((tt[o].crick=='Y' || tt[o].crick=='y') && (tt[o].minton=='Y' || tt[o].minton=='y'))
						{
							cout<<endl<<tt[o].name;
						}
					}
				}

				void C_B(CrickMinton tt[10])		// Function for list of students playing only cricket
				{
					int o;
					cout<<endl<<i-(i+j-(w-k))<<" students play only cricket";
					for(o=0;o<w;o++)
					{
						if((tt[o].crick=='Y' || tt[o].crick=='y') && (tt[o].minton!='Y' && tt[o].minton!='y'))
						{
							cout<<endl<<tt[o].name;
						}
					}
				}

				void B_C(CrickMinton tt[10])		// Function for list of students playing only badminton
				{
					int o;
					cout<<endl<<j-(i+j-(w-k))<<" students play only badminton";
					for(o=0;o<w;o++)
					{
						if((tt[o].crick!='Y' && tt[o].crick!='y') && (tt[o].minton=='Y' || tt[o].minton=='y'))
						{
							cout<<endl<<tt[o].name;
						}
					}
				}

				void CBN(CrickMinton tt[10])		// Function for list of students play neither of the game
				{
					int o;
					cout<<endl<<k<<" students play neither of the game";
					for(o=0;o<w;o++)
					{
						if((tt[o].crick!='Y' && tt[o].crick!='y') && (tt[o].minton!='Y' && tt[o].minton!='y'))
						{
							cout<<endl<<tt[o].name;
						}
					}
				}
		};
		int CrickMinton::i;
		int CrickMinton::j;
		int CrickMinton::k;

int main()
{
	cout<<"Enter number of entries!!\n";
	cin>>w;
	CrickMinton cm[w];
	int i;
	for(i=0;i<w;i++)
	{
		cm[i].get_info();
	}
	int a=1;

	while(a==1)						// loop for executing as many times as user want
	{
		cout<<"Enter 1 for list of students playing either game, 2 for list of students playing both games, 3 for list of students playing only cricket, 4 for list of students playing only badminton & 5 for list of students playing  neither game";
		cin>>i;
		switch(i)
		{
		case 1 : cm[0].C_U_B(cm); break;
		case 2 : cm[0].C_n_B(cm); break;
		case 3 : cm[0].C_B(cm); break;
		case 4 : cm[0].B_C(cm); break;
		case 5 : cm[0].CBN(cm); break;
		default:cout<<"Wrong entry";
		}
		cout<<"\nEnter 1 to continue else press 0";
		cin>>a;
	}
}


