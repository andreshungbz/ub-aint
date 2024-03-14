#include <cstring>
#include <iostream>

int mystrcmp(const char* s1, const char* s2) {
    // assume same length strings
    int result{0};

    while (*s1 != '\0') {
        if (*s1 > *s2) {
            result = 1;
            break;
        } else if (*s1 < *s2) {
            result = -1;
            break;
        }

        ++s1;
        ++s2;
    }

    return result;
}

int mystrncmp (const char* s1, const char* s2, std::size_t n) {
    int counter{0};
    int result{0};

    while (*s1 != '\0' && counter < n) {
        if (*s1 > *s2) {
            result = 1;
            break;
        } else if (*s1 < *s2) {
            result = -1;
            break;
        }

        ++s1;
        ++s2;
        ++counter;
    }

    return result;
}

int main() {
    char s1[] {"Happy New Year"};
    char s2[] {"Happy New Year"};
    char s3[] {"Happy Holidays"};
    char s4[] {"hello"};
    char s5[] {"hyllo"};

    std::cout << s1 << " and " << s2 << ": " << mystrcmp(s1, s2) << '\n';
    std::cout << s1 << " and " << s3 << ": " << mystrcmp(s1, s3) << '\n';
    std::cout << s3 << " and " << s1 << ": " << mystrcmp(s3, s1) << '\n';
    std::cout << s4 << " and " << s5 << ": " << mystrcmp(s4, s5) << '\n';

    std::cout << '\n';

    std::cout << s1 << " and " << s3 << ": " << mystrncmp(s1, s3, 6) << '\n';
    std::cout << s1 << " and " << s3 << ": " << mystrncmp(s1, s3, 7) << '\n';
    std::cout << s3 << " and " << s1 << ": " << mystrncmp(s3, s1, 7) << '\n';

    std::cout << '\n';

    std::cout << s1 << " and " << s2 << ": " << std::strcmp(s1, s2) << '\n';
    std::cout << s1 << " and " << s3 << ": " << std::strcmp(s1, s3) << '\n';
    std::cout << s3 << " and " << s1 << ": " << std::strcmp(s3, s1) << '\n';
    std::cout << s4 << " and " << s5 << ": " << std::strcmp(s4, s5) << '\n';

    std::cout << '\n';

    std::cout << s1 << " and " << s3 << ": " << std::strncmp(s1, s3, 6) << '\n';
    std::cout << s1 << " and " << s3 << ": " << std::strncmp(s1, s3, 7) << '\n';
    std::cout << s3 << " and " << s1 << ": " << std::strncmp(s3, s1, 7) << '\n';

    return 0;
}
