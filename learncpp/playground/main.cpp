#include <iostream>

int tripleNumber(int number);

int main() {
    int result{tripleNumber(2)};
    std::cout << "The number 2 cubed is: " << result << '\n';
    return 0;
}

int tripleNumber(int number) {
    int result{number * number * number};
    return result;
}
