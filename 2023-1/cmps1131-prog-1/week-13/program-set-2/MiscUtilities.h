// MiscUtilities Header File
// Project Info in driver.cpp

// these functions are opportune abstractions for the function implementations in Miscellaneous.cpp

#ifndef PROGRAM_SET_2_MISCUTILITIES_H
#define PROGRAM_SET_2_MISCUTILITIES_H

// displays feedback in response to correct or incorrect answers
void multiplicationFeedback(bool positive, int number);
// function that calculates and displays weekly pay for managers
void calculateManager();
// function that calculates and displays weekly pay for hourly workers
void calculateHourlyWorker();
// function that calculates and displays weekly pay for commission workers
void calculateCommissionWorker();
// function that calculates and displays weekly pay for pieceworkers
void calculatePieceworker();

#endif //PROGRAM_SET_2_MISCUTILITIES_H
