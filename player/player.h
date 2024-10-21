#include<iostream>
using namespace std;
#pragma once
class Player{
	int jNo;
	char name[40];
	int noOfMatches;
	int noOfRuns;
	int noOfWickets;
	public:
		Player();
		Player(int,const char*,int,int,int);
		//setters
		void setJno(int);
		void setName(const char*);
		void setMatches(int);
		void setRuns(int);
		void setWickets(int);
		//getters
		int getJno();	
		char* getName();
		int getMatches();
		int getRuns();
		int getWickets();
		//display
		void displayData();
};