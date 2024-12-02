#include <iostream>
#include <string>
using namespace std;

string getInput() {
  string temp;
  cout << "Enter a string (or 'END' to quit): ";
  cin >> temp;
  return temp;
}

bool checkValid(string user_input) {
  if (user_input.empty()) return false;
  char first = user_input.front();
  char last = user_input.back();
  return !(first == '+' || first == '-' || last == '+' || last == '-');
}

double extractNumeric(string user_input) {
  if (checkValid(user_input)) {
    cout << "valid";
  } else {
    cout << "invalid";
  }
  double result;
  return result;
}

int main() {
  string x = getInput();
  extractNumeric(x);
  return 0;
}