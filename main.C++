#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

double extractNumeric(string input) {
  // checks for + or - in any spot except first
  for (size_t i = 1; i < input.length(); ++i) {
    if (input[i] == '+' || input[i] == '-') {
      return -999999.99;
    }
  }
  // check for only 0-9, ., and +/-
  for (size_t i = 0; i < input.length(); ++i) {
    if (input[i] != '.' && input[i] != '+' && input[i] != '-' && 
        input[i] != '0' && input[i] != '1' && input[i] != '2' && 
        input[i] != '3' && input[i] != '4' && input[i] != '5' && 
        input[i] != '6' && input[i] != '7' && input[i] != '8' && 
        input[i] != '9') {
      return -999999.99;
    }
  }

  double result = 0.0;
  bool negative = false;
  size_t i = 0;
  // check for negative
  if (input[i] == '-') {
    negative = true;
    i++;
  } else if (input[i] == '+') {
    i++;
  }
  // handle before decimal
  while (i < input.length() && input[i] != '.') {
    result = result * 10 + (input[i]-'0');
    i++;
  }
  // handle after decimal
  if (i < input.length() && input[i] == '.') {
    i++;
    double decimal = 0.1;
    while (i < input.length()) {
      result += (input[i] - '0') * decimal;
      decimal /= 10;
      i++;
    }
  }
  // add back negative
  if (negative) {
    result = -result;
  }
  
  return result;
}

int main() {
  string input;
  // user input
  while (true) {
    cout << "Enter a string (or 'END' to quit): ";
    cin >> input;

    if (input == "END") {
      break;
    }
    // check valid and convert
    double number = extractNumeric(input);
    // print
    if (number != -999999.99) {
      cout << "The input is: " << fixed << setprecision(4) << number << endl;
    } else {
      cout << "The input is invalid" << endl;
    }
  }
  
  return 0;
}