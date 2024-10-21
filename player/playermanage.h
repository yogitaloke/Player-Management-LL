#include"player.h"
#include"node.h"
#pragma once
class PlayerManagement
{
	Node*start;
	public:
		PlayerManagement();
		void addPlayers(Player,int);
		void deleteJno(int);
		void update();
		void display();
		void searchByJno(int);
		void searchByName(char*);
		void sort();
		void threeSort();
		~PlayerManagement();
		void read();
		void write();
};