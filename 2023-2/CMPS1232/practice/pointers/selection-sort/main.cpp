#include <iostream>

void printArray(const int array[], int size) {
    for (int i{0}; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
}

void selectionSort(int array[], int size) {
    for (int i{0}; i < size; ++i) {
        int* smallestPtr{array + i};

        for (int j{i}; j < size; ++j) {
            if (*(array + j) < *smallestPtr) {
                smallestPtr = array + j;
            }
        }

        int temp{*(array + i)};
        *(array + i) = *smallestPtr;
        *smallestPtr = temp;
    }
}

int main() {
    const int size{5};
    int array[5] {1, 3, 2, 45, 15};

    std::cout << "Initial Array: ";
    printArray(array, size);
    std::cout << '\n';

    selectionSort(array, size);

    std::cout << "Sorted Array: ";
    printArray(array, size);
    std::cout << '\n';

    return 0;
}
