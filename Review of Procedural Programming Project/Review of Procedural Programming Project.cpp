#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayMenu();
int getPlayerChoice();
int getComputerChoice();
void determineWinner(int player, int computer);
string choiceToString(int choice);

int main() {
    srand(time(0));
    char playAgain;

    do {
        displayMenu();
        int playerChoice = getPlayerChoice();
        int computerChoice = getComputerChoice();

        cout << "You chose: " << choiceToString(playerChoice) << endl;
        cout << "Computer chose: " << choiceToString(computerChoice) << endl;

        determineWinner(playerChoice, computerChoice);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (tolower(playAgain) == 'y');

    cout << "Thanks for playing!" << endl;
    return 0;
}

void displayMenu() {
    cout << "\nRock, Paper, Scissors Game" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
}

int getPlayerChoice() {
    int choice;
    do {
        cout << "Enter your choice (1-3): ";
        cin >> choice;
    } while (choice < 1 || choice > 3);
    return choice;
}

int getComputerChoice() {
    return rand() % 3 + 1;
}

void determineWinner(int player, int computer) {
    if (player == computer) {
        cout << "It's a tie!" << endl;
    }
    else if ((player == 1 && computer == 3) || (player == 2 && computer == 1) || (player == 3 && computer == 2)) {
        cout << "You win!" << endl;
    }
    else {
        cout << "Computer wins!" << endl;
    }
}

string choiceToString(int choice) {
    switch (choice) {
    case 1: return "Rock";
    case 2: return "Paper";
    case 3: return "Scissors";
    default: return "Invalid";
    }
}
