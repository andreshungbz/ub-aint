#include <iostream>

std::size_t strlen(const char* string);

int main() {
    char string[6] {"hello"};
    std::cout << "The length of " << string << " is " << strlen(string) << '\n';

    return 0;
}

std::size_t strlen(const char* string) {
    std::size_t counter{0};

    while (*(string + counter) != '\0') {
        ++counter;
    }

    return counter;
}