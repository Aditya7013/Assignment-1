#include <iostream>
#include <ctime>
#include <cstdlib>

class GuessTheNumber {
private:
    int computerGeneratedNumber;
    int userGuessedNumber;
    int attemptCount;

public:
    GuessTheNumber() {
        attemptCount = 0;
    }

    void generateRandomNumber() {
        srand(time(0));
        computerGeneratedNumber = rand() % 100 + 1;
    }

    void startGame() {
        generateRandomNumber();

        std::cout << "Guess the number between 1 and 100 (You have 10 attempts):" << std::endl;

        while (attemptCount < 10) {
            std::cin >> userGuessedNumber;
            attemptCount++;

            if (userGuessedNumber == computerGeneratedNumber) {
                std::cout << "Congratulations! You guessed the number in " << attemptCount << " attempts." << std::endl;
                break;
            } else if (userGuessedNumber < computerGeneratedNumber) {
                std::cout << "Guessed number is smaller than the answer." << std::endl;
            } else {
                std::cout << "Guessed number is greater than the answer." << std::endl;
            }
        }

        if (attemptCount == 10) {
            std::cout << "You ran out of guesses. The number was: " << computerGeneratedNumber << std::endl;
        }
    }
};

int main() {
    GuessTheNumber game;
    game.startGame();
    return 0;
}
