#include <iostream>
#include <cstring>

using namespace std;

bool InputValidation (char[]);

int main() {
  char originalNum[] = {'1', '2', '3', '4', '5', '\0'};
  char userInput[10];
  bool valid = 0;

  cout << "WELCOME TO THE MASTERMIND GAME V1.0" << endl;
  cout << "A random number has been generated, your goal is to guess it. \n" <<
  "You have unlimited amount of guesses - press 'q' to quit any time. \n";
  cout << "Good luck! \n";

  while(valid == 0){
    cout << "Enter a 5-digit number: ";
    cin >> userInput;
    valid = InputValidation(userInput);
  }


  return 0;
}
bool InputValidation(char input[10])
{
  //Only digits
  for(int i = 0; input[i] != '\0'; i++){
    if(input[i] < '0' || input[i] > '9'){
      cout << "Your number must contain only digits \n";
      return 0;
    }
  }

  //5 digits
  int len;
  for(len = 0; input[len] != '\0'; len++); //Take string length
  if(len != 5){
    cout << "Your number must be exactly 5 digits in length! \n";
    return 0;
  }
  //No repetitions
  for(int i = 0; i < 5; i++){
    for(int j = (i+1); j < 5; j++){
      if(input[i] == input[j]){
        cout << "Your number must not have repetitive digits \n";
        return 0;
      }
    }
  }
  return 1;

}
