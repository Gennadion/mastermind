//TODO: Randomise originalNum as a string - no more hardcode
//Randomise B and W characters in response string
// Make q as a quit character
#include <iostream>
#include <cstring>

using namespace std;

bool InputValidation(char[]);
bool StringChecks(char[], char[], char[], int&);

int main() {
  char originalNum[] = {'1', '2', '3', '4', '5', '\0'};
  char userInput[10];
  char pegFeedback[] = {'_', '_', '_', '_', '_', '\0'};
  bool valid = 0, correct = 0;
  int counter = 0;

  cout << "WELCOME TO THE MASTERMIND GAME V1.0" << endl;
  cout << "A random number has been generated, your goal is to guess it. \n" <<
  "You have unlimited amount of guesses - press 'q' to quit any time. \n";
  cout << "Good luck! \n";

  while(valid == 0){
    cout << "Enter a 5-digit number (q to quit): ";
    cin >> userInput;
    valid = InputValidation(userInput);
  }

  correct = StringChecks(originalNum, userInput, pegFeedback, counter);
  while(correct == 0){
    cout << "Enter a 5-digit number (q to quit): ";
    cin >> userInput;
    correct = StringChecks(originalNum, userInput, pegFeedback, counter);
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
bool StringChecks(char origin[6], char input[10], char response[6], int& counter)
{
  //Check for blacks
  for(int i = 0; origin[i] != '\0'; i++){
    if(origin[i] == input[i]){
      response[i] = 'B';
    }
  }

  int k = 0;
  while(response[k] != '\0'){
    if(response[k] != 'B')
      break;
    k++;
  }
  if(k == 5)
    return 1;

  //Check for whites
  for(int i = 0; origin[i] != '\0'; i++){
    for(int j = 0; input[j] != '\0'; j++){
      if(origin[i] == input[j] && i != j){
        response[i] = 'W';
      }
    }
  }
  counter++;
  cout << "On try: " << counter << ", response: " << response << endl;

  //RESET
  for(int i = 0; response[i] != '\0'; i++)
    response[i] = '_';

  return 0;
  //Creating response
}
