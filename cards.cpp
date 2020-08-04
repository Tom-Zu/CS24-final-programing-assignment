//cards.cpp
//Authors: Quansen Wang & Tom Zu
//Implementation of the classes defined in cards.h
#include "cards.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string>

// create an empty list
// set the name of the player to n
CardList::CardList(string n) {
	head = 0;
	name = n;
}

//overloaded copy constructor
CardList::CardList(const CardList& source) {
	if(source.head == NULL) {head = NULL;} // check if the source list is null
	else {
		head = new Cards;
        head->suit = "";
        head->value = "";
        head->next = NULL;
        CardList::Cards *current = source.head;
        CardList::Cards *currentThis = head;
        while(current) {
            currentThis->suit = current->suit;
            currentThis->value = current->value;
            if (current->next) {
                currentThis->next = new CardList::Cards;
                currentThis = currentThis->next;
            }
            current = current->next;
        }
	}
}

// overloaded destructor
CardList::~CardList() {
	Cards *c = head;
	while(head) {
		head = head->next;
		delete c;
		c=head;
	}
}

// overloaded copy assignment
CardList& CardList::operator=(const CardList& source){
	if(!(source.head)){
		head=NULL;
		return *this;
	}
	if(head!=source.head) {
		Cards *c = head;
		while(head) {
			head = head->next;
			delete c;
			c=head;
		}

		head = new Cards;
        head->suit = "";
        head->value = "";
        head->next = NULL;
        CardList::Cards *current = source.head;
        CardList::Cards *currentThis = head;
        while(current) {
            currentThis->suit = current->suit;
            currentThis->value = current->value;
            if (current->next) {
                currentThis->next = new CardList::Cards;
                currentThis = currentThis->next;
            }
            current = current->next;
        }
        currentThis->next = NULL;
	}
	return *this;
}

// add to the end of the list
// convert char s, v to string
void CardList::append(char s, char v) {
	string su;
	string va;
	su = s;
	va = v;
	if (head == 0) {
		head = new Cards;
		head->suit = su;
		head->value = va;
		head->next = NULL;
	} else {
		Cards *c = head;
		while(c->next) {
			c=c->next;
		}
		c->next = new Cards;
		c->next->suit = su;
		c->next->value = va;
		c->next->next = 0;
	}
}

// overload operator <<
// this will print all values in the list
ostream& operator <<(ostream& os, const CardList& cl) {
	CardList::Cards *c = cl.head;
	while (c) {
		os << c->suit << " " << c->value << endl;
		c=c->next;
	}
	return os;
}
void CardList::removeCard(string source) {
	if(!head) return;
	Cards *c = head;
	// check if the head is the node that need to be removed
	// also check if the head is the only node in the list
	// if head is the only one, clear the list
	// if not, set head ptr to the second one, and delete head
	if(c->suit[0] == source[0] && c->value[0] == source[2]) {
		if (c->next == 0) {
			delete c;
			head = 0;
		} else {
			head = head->next;
			delete c;
		}
		return;
	}

	// go through the list to find the value
	// delete the node
	while(c->next) {
		if (c->next->suit[0] == source[0] && c->next->value[0] == source[2]) {
			if (c->next->next == 0) {
				delete c->next;
				c->next = 0;
			} else {
				Cards *temp = c->next->next;
				delete c->next;
				c->next = temp;
			}
			return;
		}
		c=c->next;
	}

}

// find the node with the value of source
// if not found, return false
// if the node is found, return true
bool CardList::findValue(string source) const {
	Cards *c = head;
	while(c) {
		if (c->suit[0] == source[0] && c->value[0] == source[2]) {
			return true;
		}
		c=c->next;
	}
	return false;
}

// this will take two lists and start a round
// if l1 find a match in l2
// return true
bool gameRound(CardList& l1, CardList& l2) {
  CardList::Cards *c = l1.head;
  while (c) {
  	string s = c->suit + " " + c->value;
  	if (l2.findValue(s)) {
  		cout << l1.name << " picked matching card " << s << endl;
  		l1.removeCard(s);
  		l2.removeCard(s);
  		return true;
  	}
  	c=c->next;
  }
  return false;
}