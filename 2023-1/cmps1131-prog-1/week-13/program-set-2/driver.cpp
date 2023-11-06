// [CMPS1131-1] Programming 1
// Program Set 2 - Miscellaneous Functions
// Done by Andres Hung
// Date Due: November 19, 2023

// Driver Program for the functions in Miscellaneous
// Functions in MiscUtilities are abstracted from Miscellaneous

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
#include "Miscellaneous.h"

void showMenu();
int getResponse();

int main() {
    int response;

    // NOTE: each time you finish writing a function and want to test it,
    // uncomment the case within the switch that calls that function.
    while ((response = getResponse()) != 5) {
        switch (response) {
            case 1: multiplication(); cout << "\n\n"; break;
            case 2: numberGuess(); cout << "\n\n"; break;
            case 3: printSquare(); cout << "\n\n"; break;
            case 4: calculatePayroll(); cout << "\n\n"; break;
        }
        system("pause");
    }

    cout << "\n\nThank you and have a nice day!\n\n";
    return 0;
}

void showMenu() {
    system("cls");
    cout << "***********************************\n";
    cout << "* Press 1 to do multiplication    *\n";
    cout << "* Press 2 to play number guessing *\n";
    cout << "* Press 3 to print a square       *\n";
    cout << "* Press 4 to calculate payroll    *\n";
    cout << "* Press 5 to Quit                 *\n";
    cout << "***********************************\n";
    cout << "=====> ";
}


int getResponse() {
    int response;
    showMenu();
    cin >> response;

    while (response < 1 || response > 5) {
        showMenu();
        cin >> response;
    }

    return response;
}
