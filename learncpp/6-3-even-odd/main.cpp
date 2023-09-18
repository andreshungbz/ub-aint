#include <iostream>

bool isEven(int num);

int main() {
    std::cout << "Enter an integer: ";
    int number;
    std::cin >> number;

    std::cout << number << " is " << (isEven(number) ? "even\n" : "odd\n");

    return 0;
}

bool isEven(int num) {
    return num % 2 == 0;
}