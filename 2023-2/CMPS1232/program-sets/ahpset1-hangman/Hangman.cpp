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
}

void Hangman::drawHangman(int guessCount) {
    const std::size_t height{6};
    int guessCounter{0};

    for (std::size_t i{0}; i < height; ++i) {
        switch (guessCount) {
            case 0:
                printMessage("", false, false);
                break;
            case 1:
            case 2:
                printMessage("|", false, false);
                --guessCount;
            case 3:
                printMessage("O", false, false);
                --guessCount;

        }
    }
}

void Hangman::resetAvailableLetters() {
    for (int i{0}; i < Hangman::ALPHABET_SIZE; ++i) {
        alphabetArray[i] = static_cast<char>('A' + i);
    }
}

void Hangman::setDifficultyLevel(unsigned int diffLevel) {
    difficultyLevel = (diffLevel >= 1 && diffLevel <= 3) ? diffLevel : 1;
}

unsigned Hangman::getDifficultyLevel() {
    return difficultyLevel;
}
