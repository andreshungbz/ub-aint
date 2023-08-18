#include <iostream>

double getHeight() {
    std::cout << "Enter the height of the tower in meters (m): ";
    double value{};
    std::cin >> value;
    return value;
}

double calcHeight(double gravity, double second) {
    return gravity * second * second / 2;
}

void printHeights(double gravity, double height) {
    int i{0};
    while (true) {
        double position{height - calcHeight(gravity, i)};
        if (position <= 0) {
            std::cout << "At " << i << " seconds, the ball is on the ground.\n";
            break;
        } else {
            std::cout << "At " << i << " seconds, the ball is at height: " << position << " meters\n";
            i++;
        }
    }
}

int main() {
    constexpr double gravity{9.8};
    double height{getHeight()};
    printHeights(gravity, height);
    return 0;
}