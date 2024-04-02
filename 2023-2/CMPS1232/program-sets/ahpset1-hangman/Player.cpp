// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Player Class Implementation

#include "Player.h"

// constructor sets the username and difficulty level and resets game score
Player::Player(std::string username, unsigned int level) {
    setUsername(username);
    setDifficultyLevel(level);
    resetGuessesArray();
}

// sets the difficulty level within the minimum and maximum ranges
void Player::setDifficultyLevel(unsigned int level) {
    difficultyLevel = (level >= 1 && level <= MAX_DIFFICULTY_LEVEL) ? level : 1;
}

// returns difficulty level as int
int Player::getDifficultyLevel() {
    return static_cast<int>(difficultyLevel);
}

// sets the username character by character
void Player::setUsername(std::string name) {
    std::size_t length{name.length()};

    // truncate name if it exceeds username's 20-character limit
    if (length > 20) {
        length = 20;
    }

    for (std::size_t i{0}; i < length; ++i) {
        username[i] = name[i];
    }
}

// returns username
std::string Player::getUsername() {
    return username;
}

void Player::setGuesses(unsigned int numGuesses) {
    for (std::size_t i{0}; i < 10; ++i) {
        // if there is an available space in the array, assign score and return
        if (guessesArray[i] == 0) {
            guessesArray[i] = static_cast<int>(numGuesses);
            return;
        }
    }

    // if there is no available space, reset array and assign first score
    resetGuessesArray();
    guessesArray[0] = numGuesses;
}

// sets all guesses to 0
void Player::resetGuessesArray() {
    for (std::size_t i{0}; i < 10; ++i) {
        guessesArray[i] = 0;
    }
}