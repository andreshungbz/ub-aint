// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Hangman Class Implementation
// in CLION, CMakeLists.txt as the project file
// in QT CREATOR, use ahpset1-hangman.pro as the project file

#include "Hangman.h"

Hangman::Hangman(std::string filename, std::string username) : player(username) {
    // construct pathname to word list for debug configurations
    std::string path{".."};

    // CLION relative path to wordlist.txt: ../wordlist.txt
    #if defined(__CLION_IDE__) // defined in CMakeLists.txt
        #if defined(_WIN32) || defined(_WIN64)
            path += '\\';
        #else
            path +='/';
        #endif
    // QT CREATOR relative path  to wordlist.txt ../ahpset1-hangman/wordlist.txt
    #elif defined(__QT_CREATOR__) // defined in ahpset1-hangman.pro
        #if defined(_WIN32) || defined(_WIN64)
            path += "\\ahpset1-hangman\\";
        #else
            path += "/ahpset1-hangman/";
        #endif
    #endif

    // append word list file
    path += filename;

    loadWordList(path);
    resetAvailableLetters();

    player.setDifficultyLevel(selectGameLevel()); // set difficultyLevel in Hangman's Player object
}

int Hangman::selectGameLevel() {
    while (true) {
        // use a preprocessor directive to clear screen for both Windows and macOS/Linux systems
        // https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
        // https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170
        #if defined(_WIN32) || defined(_WIN64)
            std::system("cls"); // for Windows
        #else
            std::system("clear"); // for macOS/Linux
        #endif

        std::cout << "Choose a difficulty level number [1 - Easy] [2 - Medium] [3 - Hard]: ";
        int difficultyNumber{};
        std::cin >> difficultyNumber;

        // account for failed extraction
        // e.g. if a character is inputted
        // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
        if (!std::cin) {
            std::cin.clear(); // return to normal mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        // ensure input is within valid range
        if (difficultyNumber < 1 || difficultyNumber > 3) {
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove extra input

        setDifficultyLevel(difficultyNumber); // set difficultyLevel in Hangman object
        return difficultyNumber;
    }
}

int Hangman::generateRandomNumber() {
    // use the Mersenne Twister PRNG using random devices and system clock for seeding
    // https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
    static std::random_device rd{};
    static std::seed_seq ss{static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
                     rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 mt{ss};

    // word list difficulty thresholds
    const unsigned easyThreshold{63};
    const unsigned mediumThreshold{351};
    const unsigned hardThreshold{485};

    // create number generator based on difficulty level
    unsigned level{getDifficultyLevel()};

    int min{};
    int max{};

    if (level == 1) {
        min = 0;
        max = easyThreshold;
    } else if (level == 2) {
        min = easyThreshold + 1; // 64
        max = mediumThreshold;
    } else if (level == 3) {
        min = mediumThreshold + 1; // 352
        max = hardThreshold;
    }

    std::uniform_int_distribution<int> numberGenerator{min, max};

    return numberGenerator(mt);
}

std::string Hangman::selectRandomWord(int random_number) {
    return wordVector[random_number];
}

void Hangman::loadWordList(std::string fileName) {
    std::string word;

    std::ifstream infile; // creates a file inputstream object used to connect to a text file
    infile.open (fileName); // use the inputstream object to open file

    if (infile.is_open()) { // check if the file was successfully opened
        while(!infile.eof()) { // while not at the end of file eof()
            getline(infile, word); // read a line from the file and store it in the string variable, word
            wordVector.push_back(word); // insert string word into the vector
        } // repeat until the end of file is reached

        infile.close(); // close the file once it has been processed
    } else { // if you are here, it is because there was a problem opening the file
        std::cout << "Unable to open file, " << fileName << std::endl; // notify the user that a problem has occurred
        std::cout << "Hangman game will now terminate." << std::endl;

        exit(-1); // terminate the program since no words could be loaded, making the game impossible
    }
}

void Hangman::printMessage(std::string message, bool printTop, bool printBottom) {
    const std::size_t dashesCount{33};

    // prints the top of the box
    if (printTop) {
        std::cout << '+';
        for (std::size_t i{0}; i < dashesCount; ++i) {
            std::cout << '-';
        }
        std::cout << '+';

        std::cout << '\n';
    }

    std::cout << '|';

    std::size_t messageLength{message.size()};
    std::size_t difference{dashesCount - messageLength};
    bool leftPosition{true};

    while (difference--) {
        if (leftPosition) {
            // using string methods insert and begin to append the space at the beginning
            // https://en.cppreference.com/w/cpp/string/basic_string/insert
            message.insert(message.begin(), ' ');
        } else {
            message += ' ';
        }

        leftPosition = !leftPosition;
    }

    std::cout << message;

    std::cout << '|';

    // prints the bottom of the box
    if (printBottom) {
        std::cout << '\n';

        std::cout << '+';
        for (std::size_t i{0}; i < dashesCount; ++i) {
            std::cout << '-';
        }
        std::cout << '+';
    }

    std::cout << '\n';
}

void Hangman::drawHangman(int guessCount) {
    const std::size_t height{6};
    int drawCounter{1};

    // a selective loop that draws the hangman according to guessCount
    for (std::size_t i{0}; i < height; ++i) {
        if (drawCounter <= guessCount) {
            if (drawCounter == 1 || drawCounter == 2) {
                printMessage("|", false, false);
                ++drawCounter;
                continue;
            }

            if (drawCounter == 3) {
                printMessage("O", false, false);

                // increment depends on guessCount
                if (guessCount == 3 || guessCount == 4) {
                    ++drawCounter;
                } else if (guessCount == 5) {
                    drawCounter += 2;
                } else if (guessCount > 5) {
                    drawCounter += 3;
                }

                continue;
            }

            if (drawCounter == 4 || drawCounter == 8) {
                printMessage("/  ", false, false);
                ++drawCounter;
                continue;
            }

            if (drawCounter == 5) {
                printMessage("/| ", false, false);
                ++drawCounter;
                continue;
            }

            if (drawCounter == 6) {
                printMessage("/|\\", false, false);
                ++drawCounter;
                continue;
            }

            if (drawCounter == 7) {
                printMessage("|", false, false);

                // increment depends on guessCount
                if (guessCount == 7 || guessCount == 8) {
                    ++drawCounter;
                } else if (guessCount == 9) {
                    drawCounter += 2;
                }

                continue;
            }

            if (drawCounter == 9) {
                printMessage("/ \\", false, false);
                ++drawCounter;
                continue;
            }
        } else {
            // print the rest as empty space
            printMessage("", false, false);
        }
    }
}

void Hangman::resetAvailableLetters() {
    for (int i{0}; i < Hangman::ALPHABET_SIZE; ++i) {
        alphabetArray[i] = static_cast<char>('A' + i);
    }
}

void Hangman::printAsciiMessage(std::string message) {

}

void Hangman::printAvailableLetters(std::string taken) {
    printMessage("Available Letters", true, false);

    std::size_t takenLength{taken.length()};

    for (std::size_t i{0}; i < takenLength; ++i) {
        for (int j{0}; j < Hangman::ALPHABET_SIZE; ++j) {
            // use std::toupper from <cctype> for extra validation
            // https://en.cppreference.com/w/cpp/string/byte/toupper
            if (static_cast<char>(std::toupper(taken[i])) == alphabetArray[j]) {
                alphabetArray[j] = ' ';
                break;
            }
        }
    }

    // construct string from available letters from alphabetArray
    std::string availableLetters{};
    for (int i{0}; i < Hangman::ALPHABET_SIZE; ++i) {
        availableLetters += alphabetArray[i];
    }

    printMessage(availableLetters, true, false);
}

bool Hangman::checkWin(std::string wordToGuess, std::string guessesSoFar) {
    std::size_t wordToGuessLength{wordToGuess.length()};

    // convert wordToGuess to uppercase
    for (std::size_t i{0}; i < wordToGuessLength; ++i) {
        wordToGuess[i] = static_cast<char>(std::toupper(wordToGuess[i]));
    }

    // convert guessesSoFar to uppercase just in case
    for (std::size_t i{0}; i < guessesSoFar.length(); ++i) {
        guessesSoFar[i] = static_cast<char>(std::toupper(guessesSoFar[i]));
    }

    std::string wordField{};
    std::size_t lettersGuessed{0};

    // first variable is used to not append a leading space
    bool first{true};
    for (std::size_t i{0}; i < wordToGuessLength; ++i) {
        if (first) {
            first = false;
        } else {
            wordField += ' ';
        }

        if (guessesSoFar.find(wordToGuess[i]) != std::string::npos) {
            wordField += wordToGuess[i];
            ++lettersGuessed;
        } else {
            wordField += '_';
        }
    }

    printMessage(wordField, true, false);

    // if the count of lettersGuessed is equal to the word length, then all letters have been guessed
    // and player has won
    return wordToGuessLength == lettersGuessed;
}

bool Hangman::processResults(std::string wordToGuess, int guessAttempts, bool hasWon) {
    player.setGuesses(guessAttempts);
    player.generateStatistics();

    if (hasWon) {
        printAsciiMessage("YOU WON!");
    } else {
        printAsciiMessage("GAME OVER!");
    }

    while (true) {
        std::cout << "Would you like to play again? [Y] [N]: ";
        int response{};
        std::cin >> response;

        // account for failed extraction
        // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
        if (!std::cin) {
            std::cin.clear(); // return to normal mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove extra input

        if (response == 'Y' || response == 'y') {
            player.setDifficultyLevel(selectGameLevel());

            return true;
        } else {
            return false;
        }
    }
}

void Hangman::setDifficultyLevel(unsigned int diffLevel) {
    difficultyLevel = (diffLevel >= 1 && diffLevel <= 3) ? diffLevel : 1;

    if (difficultyLevel == 1 || difficultyLevel == 3) {
        setMaxAllowedAttempts(10);
    } else {
        // if difficulty level is 2
        setMaxAllowedAttempts(13);
    }
}

unsigned Hangman::getDifficultyLevel() {
    return difficultyLevel;
}

void Hangman::setMaxAllowedAttempts(unsigned int allowedAttempts) {
    maxAllowedAttempts = allowedAttempts;
}

unsigned Hangman::getMaxAllowedAttempts() {
    return maxAllowedAttempts;
}

unsigned Hangman::attemptsMadeSoFar(std::string wordToGuess, std::string guessesSoFar) {
    std::size_t guessesLength{guessesSoFar.length()};
    unsigned notInWordCounter{0};

    for (std::size_t i{0}; i < guessesLength; ++i) {
        // use std::string find member function and std::tolower function from <cctype> to compare characters
        // https://en.cppreference.com/w/cpp/string/byte/tolower
        // https://en.cppreference.com/w/cpp/string/basic_string/find
        if (wordToGuess.find(static_cast<char>(std::tolower(guessesSoFar[i]))) == std::string::npos) {
            ++notInWordCounter;
        }
    }

    return notInWordCounter;
}
