// task1_number_guessing.cpp

#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    srand(time(0));  // seed random number
    int number = rand() % 100 + 1;  // random number between 1 to 100
    int guess;

    cout << "?? Welcome to the Number Guessing Game!\n";
    do {
        cout << "Guess a number (1 to 100): ";
        cin >> guess;

        if (guess > number)
            cout << "Too high! Try again.\n";
        else if (guess < number)
            cout << "Too low! Try again.\n";
        else
            cout << "?? Congratulations! You guessed it right.\n";

    } while (guess != number);

    return 0;
}
