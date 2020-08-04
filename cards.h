//cards.h
//Authors: Quansen Wang & Tom Zu
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include "cards.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string>

class CardList {
public:
	CardList(string n); // constructor that set the name of player to n
	void append(char s, char v); // add node to the end of the llist
	void removeCard(string source); // find the node with the value of source, delete that node
	bool findValue(string source) const; // find match in the list

	string getName() {
		return name;
	}
	string getCards() {
		Cards *c = head;
		string s="";
		while(c) {
			s+=c->suit + " " + c->value;
			s+="\n";
			c=c->next;
		}
		return s;
	}

	~CardList();
	CardList(const CardList& source);
	CardList& operator=(const CardList& source);

	friend bool gameRound(CardList& l1, CardList& l2);
	friend ostream& operator <<(ostream& os, const CardList& cl);

private:
	struct Cards {
		string suit;
		string value;
		Cards* next;
	};
	Cards *head;
	string name;
};

#endif