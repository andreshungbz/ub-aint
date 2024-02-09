#include <iostream>

bool inArray(const int arr[], int num, std::size_t len);
void eliminate_duplicates(int arr[], std::size_t len);

int main() {
    const std::size_t size{5};
    int array[size] {1, 2, 1, 5, 2};

    std::cout << "After: ";
    eliminate_duplicates(array, size);
    std::cout << '\n';

    return 0;
}

bool inArray(const int arr[], int num, std::size_t len) {
    for (std::size_t i{0}; i < len; ++i) {
        if (arr[i] == num) {
            return true;
        }
    }

    return false;
}

void eliminate_duplicates(int arr[], std::size_t len) {
    std::size_t arrCounter{0};
    int newArray[len];

    for (std::size_t i{0}; i < len; ++i) {
        if (!inArray(newArray, arr[i], arrCounter)) {
            newArray[arrCounter] = arr[i];
            ++arrCounter;
        }
    }

    for (std::size_t i{0}; i < arrCounter; ++i) {
        std::cout << newArray[i] << ' ';
    }
}