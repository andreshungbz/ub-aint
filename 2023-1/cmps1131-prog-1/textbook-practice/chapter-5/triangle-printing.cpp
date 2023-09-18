#include <iostream>

void triangleA(int height);
void triangleB(int height);
void triangleC(int height);
void triangleD(int height);

int main() {
    triangleD(10);
    return 0;
}

void triangleA(int height) {
    for (int i{1}; i <= height; ++i) {
        for (int j{0}; j < i; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void triangleB(int height) {
    for (int i{0}; i < height; ++i) {
        for (int j{height - i}; j > 0; --j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void triangleC(int height) {
    for (int i{0}; i < height; ++i) {
        for (int j{0}; j < i; ++j) {
            std::cout << ' ';
        }
        for (int k{height - i}; k > 0; --k) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void triangleD(int height) {
    for (int i{1}; i <= height; ++i) {
        for (int j{height - i}; j > 0; --j) {
            std::cout << ' ';
        }
        for (int k{0}; k < i; ++k) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}