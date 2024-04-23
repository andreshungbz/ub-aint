#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    // can change file location
    std::fstream ioFile{"../input.txt", std::ios::in | std::ios::out};

    if (!ioFile) {
        std::cerr << "File could not be opened.\n";
        std::exit(1);
    }

    std::cout << "Locations changed:";

    while (!ioFile.eof()) {
        int character{ioFile.get()};

        if (character == 'i' || character == 'I') {
            // move file pointer behind one place to replace
            // both seekp and tellg refer to the same file pointer
            ioFile.seekp(-1, std::ios::cur);
            std::cout << ' ' << ioFile.tellg();
            ioFile << '$';
        }
    }

    std::cout << '\n';

    return 0;
}
