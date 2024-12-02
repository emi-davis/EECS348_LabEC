#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

double extractNumeric(string input) {
  for (size_t i = 1; i < input.length(); ++i) {
    if (input[i] == '+' || input[i] == '-') {
      return -999999.99;
    }
  }

  double result = 0.0;
  bool negative = false;
  size_t i = 0;
  
  if (input[i] == '-') {
    negative = true;
    i++;
  } else if (input[i] == '+') {
    i++;
  }

  while (i < input.length() && input[i] != '.') {
    result = result * 10 + (input[i]-'0');
    i++;
  }

  if (i < input.length() && input[i] == '.') {
    i++;
    double decimal = 0.1;
    while (i < input.length()) {
      result += (input[i] - '0') * decimal;
      decimal /= 10;
      i++;
    }
  }

  if (negative) {
    result = -result;
  }
  
  return result;
}

int main() {
  string input;
  while (true) {
    cout << "Enter a string (or 'END' to quit): ";
    cin >> input;

    if (input == "END") {
      break;
    }

    double number = extractNumeric(input);

    if (number != -999999.99) {
      cout << "The input is: " << fixed << setprecision(4) << number << endl;
    } else {
      cout << "The input is invalid" << endl;
    }
  }
  
  return 0;
}