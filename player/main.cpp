#include "playermanage.h"
int main1()
{
	PlayerManagement pm;
	pm.sort();
}
int main() 
{
	PlayerManagement pm;
	int choice;
	while (choice!=8)
	{
		cout<<"\n\n\t Press 1 to Add the player";
		cout<<"\n\t Press 2 to display player";
		cout<<"\n\t Press 3 to delete player";
		cout<<"\n\t Press 4 to update player";
		cout<<"\n\t Press 5 to sort player";
		cout<<"\n\t Press 6 to Top three player";
		cout<<"\n\t Press 7 to Search";
		cout<<"\n\t8.Exit";
		cout<<"\n Enter your choice:  ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					int jNo;
					char name[40];
					int noOfMatches;
					int noOfRuns;
					int noOfWickets,pos;
					cout<<"\nEnter the jersey number: ";
					cin>>jNo;
					fflush(stdin);
					cout<<"Enter the player name: ";
					gets(name);
					cout<<"Enter the no of matches: ";
					cin>>noOfMatches;
					cout<<"Enter the Runs: ";
					cin>>noOfRuns;
					cout<<"Enter the Wickets: ";
					cin>>noOfWickets;
					Player p1(jNo,name,noOfMatches,noOfRuns,noOfWickets);
					cout<<"Enter the position: ";
					cin>>pos;
					pm.addPlayers(p1,pos);
				}
				break;
			case 2:
				{
					pm.display();
				}
				break;
			case 3:
				{
					int no;
					cout<<"Enter the jersey number do you want to delete";
					cin>>no;
					pm.deleteJno(no);
				}
				break;
			case 4:
				{
					pm.update();	
				}
				break;
			case 5:
				{
					pm.sort();
					pm.display();
				}
				break;
			case 6:
				{
					pm.threeSort();
				}
				break;
			case 7:
				{
					int ch;
					cout<<"Enter choice do you want to search \n1.By name \n2.By Jersey number"<<endl;
					cin>>ch;
					if(ch==1)
					{
						char nm[20];
						cout<<"Enter the player name do you want to search";
						cin>>nm;
						pm.searchByName(nm);
					}
					else if(ch==2)
					{
						int jno;
						cout<<"Enter the player jersey no do you want to search";
						cin>>jno;
						pm.searchByJno(jno);
					}
					else
					{
						cout<<"You enter wrong choice";
					}
				}
				break;
		}
		
	}	
	return 0;
}