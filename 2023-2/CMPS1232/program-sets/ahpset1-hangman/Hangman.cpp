// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Hangman Class Implementation

#include "Hangman.h"

Hangman::Hangman(std::string filename, std::string username) : player(username) {
    // loadWordList(filename);

    // NOTE: program set specifications have setDifficultyLevel run both in selectGameLevel AND here...
    player.setDifficultyLevel(selectGameLevel());
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

        player.setDifficultyLevel(difficultyNumber); // redundant in constructor, can be commented out
        return difficultyNumber;
    }
}