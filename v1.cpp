#include <iostream>
#include <cstring>

using namespace std;

bool InputValidation (char[]);

int main() {
  char originalNum[] = {'1', '2', '3', '4', '5', '\0'};
  char userInput[10];

  cout << "WELCOME TO THE MASTERMIND GAME V1.0" << endl;
  cout << "A random number has been generated, your goal is to guess it." << endl
  << "You have unlimited amount of guesses - press 'q' to quit any time." << endl;
  cout << "Good luck!" << endl;

  cout << "Enter a 5-digit number: ";
  cin >> userInput;

  int valid = InputValidation(userInput);


  return 0;
}
bool InputValidation(char input[10])
{
  //Only digits
  for(int i = 0; input[i] != '\0'; i++){
    if(input[i] < '0' || input[i] > '9'){
      cout << "Your number must contain only digits" << endl;
      return 0;
    }
  }

  //5 digits
  for(int i = 0; input[i] != '\0'; i++); //Take string length
  //No repetitions
}
