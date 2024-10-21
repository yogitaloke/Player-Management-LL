#include"player.h"
class Node{
	Player data;
	Node* next;
	public:
		Node(Player);
		void setData(Player);
		void setNext(Node*);
		Player getData();
		Node* getNext();
};