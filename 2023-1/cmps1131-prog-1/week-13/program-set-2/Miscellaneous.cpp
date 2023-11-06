// Miscellaneous Functions Implementation
// Project Info in driver.cpp

// implementation of the program set functions

#include "Miscellaneous.h"
#include <iostream>
#include <iomanip>
// used in multiplication practice program
#include <cstdlib>
#include <ctime>
// used in number guessing game
#include <random>

// additional opportune abstractions are abstracted in Utilities.h and Utilities.cpp
#include "MiscUtilities.h"

void multiplication() {
    // nullptr is type-safe and can be used instead of 0
    // https://community.ibm.com/community/user/ibmz-and-linuxone/blogs/fang-lu2/2020/03/24/nullptr-in-c11
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // this multiplication practice program contains 10 questions and tracks correct answers
    const int numberOfQuestions = 10;
    int correctCount = 0;

    for (int i{1}; i <= numberOfQuestions; ++i) {
        // generate two random one-digit positive integers and calculate their product
        int firstNumber{1 + std::rand() % 9};
        int secondNumber{1 + std::rand() % 9};
        int answer{firstNumber * secondNumber};

        // generate random feedback response numbers
        int correctFeedback{1 + std::rand() % 4};
        int incorrectFeedback{1 + std::rand() % 4};

        std::cout << '\n' << '[' << i << "] How much is " << firstNumber << " times " << secondNumber << "? ";
        int response;
        std::cin >> response;

        if (response == answer) {
            ++correctCount;
            // display random correct feedback response
            multiplicationFeedback(true, correctFeedback);
        } else {
            // display random incorrect feedback response
            multiplicationFeedback(false, incorrectFeedback);

            // allow user to keep trying until they get the right answer
            while (response != answer) {
                std::cout << "What is " << firstNumber << " times " << secondNumber << "? ";
                std::cin >> response;

                if (response == answer) {
                    multiplicationFeedback(true, correctFeedback);
                    break;
                } else {
                    // generate new random incorrect feedback response
                    incorrectFeedback = 1 + std::rand() % 4;
                    multiplicationFeedback(false, incorrectFeedback);
                }
            }
        }
    }

    // display practice percentage
    double practicePercentage{static_cast<double>(correctCount) / numberOfQuestions * 100};
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "\nYour percentage of correct responses is " << practicePercentage << "%!\n";

    // additional feedback indicated in case of percentage being less than 75%
    if (practicePercentage < 75.0) {
        std::cout << "Please ask your instructor for extra help.\n";
    }
}

void numberGuess() {
    // the program set specification did not mention using rand() for this problem, therefore I am not using it here
    // the Mersenne Twister is a comparatively more effective PRNG than rand()
    // https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/

    // random generation setup
    // https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
    std::random_device rd{};
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{ss};
    std::uniform_int_distribution<> range{1, 1000};

    int randomNumber{range(mt)};
    int guess{0};
    int numberOfGuesses{0};
    bool game{true};

    // the outer while loop is for every new game state
    // the inner while loop is for every guess made
    while (guess != randomNumber) {
        std::cout << "\nI have a number between 1 and 1000.\n"
            << "Can you guess my number?\n"
            << "Please type your first guess.\n";

        while (guess != randomNumber && game) {
            std::cout << "Guess [" << numberOfGuesses + 1 << "]: ";
            std::cin >> guess;

            // skip guess if it is outside the range
            if (guess < 1 || guess > 1000) continue;

            ++numberOfGuesses;

            if (guess < randomNumber) {
                std::cout << "Too low. Try again.\n";
            } else if (guess > randomNumber) {
                std::cout << "Too high. Try again.\n";
            } else {
                std::cout << "\nExcellent! You guessed the number in " << numberOfGuesses << " guesses!\n";

                // program set specification specifically indicates both <= 10 and == 10
                // so having exactly 10 guesses displays 2 messages
                if (numberOfGuesses <= 10) {
                    std::cout << "Either you know the secret or you got lucky!\n";
                }
                if (numberOfGuesses == 10) {
                    std::cout << "Ahah! You know the secret!\n";
                }
                if (numberOfGuesses > 10) {
                    std::cout << "You should be able to do better!\n";
                }

                std::cout << "Would you like to continue (y/n): ";
                char response;
                std::cin >> response;

                if (response == 'y' || response == 'Y') {
                    // reset the game state
                    randomNumber = range(mt);
                    guess = 0;
                    numberOfGuesses = 0;
                    // break out of loop but maintain game true so that another game is played
                    break;
                } else {
                    // this will break out of the inner and outer while loops
                    game = false;
                }
            }
        }
    }
}

void printSquare() {
    int size{0};

    // enforce size constraint 1 - 20
    while (!(size >= 1 && size <= 20)) {
        std::cout << "Enter size of square (1 - 20): ";
        std::cin >> size;
    }

    // hollow squares are not possible for sizes 1 and 2
    if (size < 3) {
        for (int i{1}; i <= size; ++i) {
            for (int j{1}; j <= size; ++j) {
                std::cout << '*';
            }
            std::cout << '\n';
        }
    } else {
        // for squares with hollow spaces
        const int spaces{size - 2};
        for (int i{1}; i <= size; ++i) {
            // the first and last iterations contain all asterisks
            if (i == 1 || i == size) {
                for (int j{1}; j <= size; ++j) {
                    std::cout << '*';
                }
            } else {
                std::cout << '*';
                for (int j{1}; j <= spaces; ++j) {
                    std::cout << ' ';
                }
                std::cout << '*';
            }
            std::cout << '\n';
        }
    }
}

void calculatePayroll() {
    int payCode{0};
    bool payRoll{true};

    std::cout << "Employee Pay Codes\n"
        << "[1] Manager\n" << "[2] Hourly Worker\n"
        << "[3] Commission Worker\n" << "[4] Pieceworker\n";

    // displays monetary values correctly
    std::cout << std::setprecision(2) << std::fixed;

    while (payRoll) {
        // enforce option constraint 1 - 5
        while (!(payCode >= 1 && payCode <= 5)) {
            std::cout << "\nEnter employee pay code (1 - 4) (5 to exit): ";
            std::cin >> payCode;
        }

        // abstracting into functions resolved scoping issues
        switch (payCode) {
            case 1:
                calculateManager();
                break;
            case 2:
                calculateHourlyWorker();
                break;
            case 3:
                calculateCommissionWorker();
                break;
            case 4:
                calculatePieceworker();
            case 5:
                payRoll = false;
            default:
                break;
        }

        // reset pay code to prompt again
        payCode = {0};
    }
}