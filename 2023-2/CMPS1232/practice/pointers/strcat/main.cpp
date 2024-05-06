#include <iostream>

char* mystrcat(char* s1, const char* s2) {
    while (*(s1) != '\0') {
        ++s1;
    }

    while (*s2 != '\0') {
        *(s1) = *(s2);
        ++s1;
        ++s2;
    }

    *(s1) = '\0';

    return s1;
}

int main() {
    char s1[20] {"Happy "};
    char s2[] {"New Year "};

    std::cout << "s1 = " << s1 << "\ns2 = " << s2;

    mystrcat(s1, s2);

    std::cout << "\n\nAfter strcat(s1, s2):\ns1 = " << s1 << "\ns2 = " << s2;
    return 0;
}
