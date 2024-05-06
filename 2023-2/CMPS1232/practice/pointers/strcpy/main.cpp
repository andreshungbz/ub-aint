#include <iostream>

char* strcpy(char *s1, const char *s2);

int main() {
    char x[] {"Happy Birthday to You"}; // 21
    char y[25];

    strcpy(y, x);

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    return 0;
}

char* strcpy(char *s1, const char *s2) {
    int counter{0};

    while (*(s2 + counter) != '\0') {
        *(s1 + counter) = *(s2 + counter);
        ++counter;
    }

    *(s1 + counter) = '\0';

    return s1;
}