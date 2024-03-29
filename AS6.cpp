//     Chase Burr
//     CS 2130 – 11:30am - 1:20pm
//     Individual Assignment #6
//     Dr. Huson
//     Due: 04/18/19
//     Filename: AS6.cpp
//     Version: 1.0
// ---------------------------------------------------------------
//     description
// ---------------------------------------------------------------

#include <iostream>
#include <cstring>
#include  <string>
using namespace std;

static int nextState(int state, char symbol[30]);
static bool accept(int state);
static bool validString(string word);

int main() {
  int state = 0;
  char input[30];
  cout << "Input string: ";
  cin.getline(input, 30);

  cout << "End State = " << nextState(state, input) << endl;
  cout << "Accepted: " << accept(nextState(state, input)) << endl;
  cout << "Valid String: " << validString(input) << endl;

  return 0;
}

static int nextState(int state, char symbol[30]) {
  char ascii;
  int moveState[4][3] = { {0, 0, 1},  // 0
                          {0, 0, 2},  // 1
                          {2, 3, 2},  // 2
                          {2, 3, 2} };// 3
  // for loop that checks for invalid characters
  for (size_t i = 0; i < strlen(symbol); i++) {
    if (symbol[i] == 'a' || symbol[i] == 'b' || symbol[i] == 'c') {
      continue;
    } else { return -1; }
  }
  // loops through each character and sets the state
  for (size_t i = 0; i < strlen(symbol); i++) {
    ascii = symbol[i] - 97;
    state = moveState[state][ascii];
  }
  return state;
}

static bool accept(int state) { // if state ends in 0 - 2 then not accepted
  if (state == 3) {
    return true;
  } else { return false; }
}
static bool validString(string word) {
  int state = 0; // temp variable
  //nextState(state, word);
  if (state == 3) {
    return true;
  } else { return false; }
}
