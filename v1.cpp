#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

bool InputValidation(char[]); //Validates User Input
bool StringChecks(char[], char[], char[], int&); //Checks if string matches the origin and returns pegs
void GenerateNumber(char[][6], char[]); //Picks a random 5-digit number string
void ResponseShuffle(char[]); //Shuffles peg response on the guess
void Endgame(char[], char[], bool&, int&); //Checks conditions for the game to end

const int MAX_GUESS = 15;

int main() {
  char preDefinedArrays[6][6] = {"83452", "03921", "74520", "98053","69534", "12874"};
  char originalNum[6];
  char userInput[10];
  char pegFeedback[] = {'_', '_', '_', '_', '_', '\0'};
  bool valid = 0, correct = 0;
  int counter = 0;

  srand(time(0));


  cout << "WELCOME TO THE MASTERMIND GAME 1.0.6" << endl;
  cout << "A random number has been generated, your goal is to guess it. \n";


  do {
    cout << "You have " << MAX_GUESS << " guesses - press 'q' to quit any time. \n";
    cout << "Good luck! \n";
    GenerateNumber(preDefinedArrays, originalNum);
    //cout << originalNum; For tests

    while(correct == 0 && counter < MAX_GUESS){
      cout << "Enter a 5-digit number (q to quit): ";
      cin >> userInput;
      valid = InputValidation(userInput); //Pre-condition check
      while(valid == 0){
        cout << "Enter a 5-digit number (q to quit): ";
        cin >> userInput;
        valid = InputValidation(userInput);
      }
      correct = StringChecks(originalNum, userInput, pegFeedback, counter);
    }

    Endgame(userInput, originalNum, correct, counter);
  } while(counter < MAX_GUESS);

  return 0;
}
bool InputValidation(char input[10])
{
  //Exit value
  if(input[0] == 'q')
    return 1;

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
  if(input[0] == 'q')
    return 1;
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

  ResponseShuffle(response);
  cout << "On try: " << counter << ", response: " << response << endl;

  //RESET
  for(int i = 0; response[i] != '\0'; i++)
    response[i] = '_';

  return 0;
}
void GenerateNumber(char storage[6][6], char origin[6])
{
  srand(time(0));
  int randNum = rand() % 6;
  for (int j = 0; j < 6; ++j)
    origin[j] = storage[randNum][j];
}
void ResponseShuffle(char string[6])
{
  //Swaps 2 characters in the string
  char temp = string[0];
  string[0] = string[2];
  string[2] = temp;

  temp = string[1];
  string[1] = string[3];
  string[3] = temp;
}
void Endgame(char input[10], char origin[6], bool& win, int& counter)
{
  if(input[0] == 'q'){
    cout << "Ok, you lost! Goodbye!";
    counter = (MAX_GUESS + 1);
  }

  if(win == 1)
    cout << "Congratulations! The number was: " << origin << endl;

  if(counter >= MAX_GUESS)
    cout << "You have exhausted all your tries!" << endl;

  //RESTART MENU
  cout << "Do you want to play again? (y/n)" << endl;
  char restart;
  cin >> restart;
  if(restart == 'y'){
    counter = 0;
    win = 0;
  }
  else{
    cout << "Goodbye!";
    counter = (MAX_GUESS + 1);
  }
}
