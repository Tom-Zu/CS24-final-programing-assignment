#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "cards.h"

// this function will start a game
// it will end until the game round return a false
void startGame(CardList& l1, CardList& l2) {
  if (gameRound(l1,l2)) {
    startGame(l2,l1);
  }
  return;
}

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  CardList alice("Alice");
  CardList bob("Bob");

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    alice.append(line[0], line[2]);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    bob.append(line[0], line[2]);
  }
  cardFile2.close();

  // Start the game
  
  // start with Alice, if a match found, use the posi to find the card and remove it
  // as well as print it out
  // if the match is found, switch to bob
  // start the loop at count
  // if a match found, print it and remove it
  startGame(alice, bob);
  // no match found
  // end the game
  cout << endl;
  cout << "Alice's cards:" << endl;
  cout << alice;
  cout << endl;
  cout << "Bob's cards:" << endl;
  cout << bob;
  return 0;
}