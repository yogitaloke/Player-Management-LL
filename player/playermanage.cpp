#include"playermanage.h"
#include<fstream>
/////////////////////////////////////////////////////////////
PlayerManagement::PlayerManagement()
{
	start=NULL;
	read();
}
void PlayerManagement:: addPlayers(Player p1,int pos)
{
	Node*temp= new Node(p1);
	if(start==NULL)
	{
		start=temp;
		return;
	}
	if(pos==1)
	{
		temp->setNext(start);
		start=temp;
		return ;
	}
	Node* p=start;
	int i=1;
	while(i<pos-1&&p->getNext()!=NULL)
	{
		i++;
		p=p->getNext();
	}
	temp->setNext(p->getNext());
	p->setNext(temp);
}
/////////////////////////////////////////////////////////////
void PlayerManagement:: deleteJno(int jno)
{
	if(start==NULL)
	{
		cout<<"No nodes present to delete";
		return;
	}
	Node*p=start;
	int count=0;
	while(p->getNext()!=NULL&&p->getData().getJno()!=jno)
	{
		p=p->getNext();
		count++;
	}
	if(p->getData().getJno()==jno)
	{
		if(count==0)
		{
			start=p->getNext();
			delete p;
			cout<<"\n\n delete sucessfully";	
			return;
		}
		else
		{
			Node*q=start;
			while(p!=q->getNext())
			{
			q=q->getNext();
			}
			q->setNext(p->getNext());
			delete p;
			cout<<"\n\n delete middle sucessfully";	
		}
	}
	else
	{
		cout<<"player  not present";
	}  
}
/////////////////////////////////////////////////////////////
void PlayerManagement:: update()
{
	int jno;
	cout<<"Enter the jno  do you want to update";
	cin>>jno;
	Node*p=start;
	while(p->getNext()!=NULL&&p->getData().getJno()!=jno)
	{
		p=p->getNext();
	}
	if(p->getData().getJno()==jno)
	{
				int ch;
			cout<<"\nt1.Update Matches";
			cout<<"\nt2.Update Runs";
			cout<<"\nt3.Update Wickets";
			cout<<"\nEnter the choice";
			cin>>ch;
			if(ch==1)
			{
				int no;
				cout<<"Enter the number";
				cin>>no;
				Player p1=p->getData();
				p1.setMatches(no);
				p->setData(p1);
				return;
			}
			else if(ch==2)
			{
				int run;
				cout<<"Enter the Runs";
				cin>>run;
				Player p1=p->getData();
				p1.setRuns(run);
				p->setData(p1);
			}
			else if(ch==3)
			{
				int wicket;
				cout<<"Enter the wickets";
				cin>>wicket;
				Player p1=p->getData();
				p1.setWickets(wicket);
				p->setData(p1);
			}
			else
			{
				cout<<"Enter wrong choice";
			}
	}
	else
	{
		cout<<"Player not found";
	}
}
/////////////////////////////////////////////////////////////
void PlayerManagement:: display()
{
	if(start==NULL)
	{
		cout<<"NO elemets to display";
		return;
	}
	else
	{
		Node*p=start;
		while(p->getNext()!=NULL)
		{
            p->getData().displayData();
			p=p->getNext();
		} 
		p->getData().displayData();                        
	}
}
/////////////////////////////////////////////////////////////
void PlayerManagement:: searchByJno(int no)
{
	   if(start==NULL)
		{
			cout<<"no data present to search";
		}
		else
		{
			Node*p=start;
			while( p->getData().getJno()!=no &&p->getNext()!=NULL )
			{
				p=p->getNext();
			}
		    if(p->getData().getJno()==no)
			{
				cout<<no<<"\n\n\n present";
             p->getData().displayData();
		    }
		    else 
		    {
		    	cout<<"\n\n\n not present";
		    	
			}
	    }		
}
///////////////////////////////////////////////////////////////
void PlayerManagement:: searchByName(char*pName)
{
	if(start==NULL)
	{
		cout<<"No data present to search\n";
	}
	else
	{
		Node*p=start;
		while(p->getNext()!=NULL&& (strcasecmp(p->getData().getName(),pName)!=0))
		{
			p=p->getNext();
	    }
		if(strcasecmp(p->getData().getName(),pName)==0)
		{
			cout<<"Book name "<<pName<<" present";
			p->getData().displayData();
		}
		else
		{
			cout<<"player name not present";
		}
    }	
}
/////////////////////////////////////////////////////////////
void PlayerManagement:: sort()
{
	int ch;
	cout<<"Enter the choice \n 1.Sort by Runs 2.Sort by Wickets 3.Sort by Matches    ";
	cin>>ch;
	           
		              	if(ch==1)//sort by runs
						{
							for(Node*p=start;p!=NULL;p=p->getNext())
	                       {
		                     for(Node*q=p->getNext();q!=NULL;q=q->getNext())
		                      {
						    	if(p->getData().getRuns()<q->getData().getRuns())
		    	                 {
			    	              	Player temp =p->getData();
			    		            p->setData(q->getData());
			    		            q->setData(temp);
				                 }
				              }
				           }
				         // display();
				         }
				        else if(ch==2)//sort by Wickets
						{
				            for(Node*p=start;p!=NULL;p=p->getNext())
	                         {
		                      for(Node*q=p->getNext();q!=NULL;q=q->getNext())
		                       {
						         if(p->getData().getWickets()<q->getData().getWickets())
		    	                  {
			    	              	Player temp =p->getData();
			    		            p->setData(q->getData());
			    		            q->setData(temp);
				             	  }
				               }
				             }
						}
						
						else if(ch==3)//sort by matches
						{
							for(Node*p=start;p!=NULL;p=p->getNext())
	                         {
		                      for(Node*q=p->getNext();q!=NULL;q=q->getNext())
		                       {
						         if(p->getData().getMatches()<q->getData().getMatches())
				    	             {
				    	              	Player temp =p->getData();
				    		            p->setData(q->getData());
				    		            q->setData(temp);
						             }
				               }
				             }
						}
						else
						{
							cout<<"invalid choice"; 
						}
							
}
/////////////////////////////////////////////////////////////
void PlayerManagement:: threeSort()
{
	sort();	
		Node*p=start;
		int i=1;
		while(p->getNext()!=NULL&&i<3)
		{
            p->getData().displayData();
			p=p->getNext();
			i++;
		} 
		p->getData().displayData();
	
}
///////////////////////////////////////////////////////////////
PlayerManagement::~PlayerManagement()
{
	write();
	Node*p=start;
	p=start;
	while(start!=NULL)
	{
		start=start->getNext();
		delete p;
		p=start;
		cout<<"destructor called";
	}
}
/////////////////////////////////////////////////////////////
void PlayerManagement:: read()
{
	cout<<"readdddddddddddddddddddddddddddddddddddddddddd";
	int i=1;
	ifstream in("player.dat",ios_base::binary);
	while(!in.eof())
	{
		Player p1;
		in.read((char*)&p1,sizeof(p1));
		if(in.eof())
		{
			break;
		}
		addPlayers(p1,i);
		i++;
	}
	in.close();	
}
////////////////////////////////////////////////////////////////////////////////
void PlayerManagement:: write()
{
	Node*p=start;
	ofstream abc("player.dat",ios_base::binary);
	while(p!=NULL)
	{
		Player p1=p->getData();
		abc.write((char*)&p1,sizeof(p1));
		p=p->getNext();
        cout<<"write done!!!!!!!!!!!!";
        cout<<endl;
	}
	abc.close();	
}
