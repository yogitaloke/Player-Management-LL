#include"player.h"
////////////////////////////////////////////////////
Player ::Player()
{
	this->jNo=0;
	strcpy(this->name,"Not given !!");
	this->noOfMatches=0;
	this->noOfRuns= 0;
	this->noOfWickets=0;
}
Player ::Player(int j,const char* nm,int m,int r,int w)
{
	this->jNo=j;
	strcpy(this->name,nm);
	this->noOfMatches=m;
	this->noOfRuns=r;
	this->noOfWickets=w;
	
}
//setters
void Player :: setJno(int j)
{
		this->jNo=j;
}
void Player :: setName(const char* nm)
{
	strcpy(this->name,nm);
}
void Player :: setMatches(int m)
{
	this->noOfMatches=m;
}
void Player :: setRuns(int r)
{
	this->noOfRuns=r;
}
void Player :: setWickets(int w)
{
	this->noOfWickets=w;
}
//getters
int Player :: getJno()
{
	return jNo;
}
char* Player :: getName()
{
	return name;
}
int Player :: getMatches()
{
	return noOfMatches;
}
int Player :: getRuns()
{
	return noOfRuns;
}
int Player :: getWickets()
{
	return  noOfWickets;
}
//display
void Player ::  displayData()
{
	cout<<"\n\n----------------Player--------------------\n";
	cout<<"\n\tJersey Number: " <<this->jNo;
	cout<<"\n\tPlayer Name:" <<this->name;
	cout<<"\n\tNo of mathches:"<<this->noOfMatches;
	cout<<"\n\tNo of Runs: "<<this->noOfRuns;
	cout<<"\n\tNo of Wickets: "<<this->noOfWickets;
	
}