#include <iostream>
using namespace std;

int main() {
    // Print a message
    std::cout << "Hello, World!" << std::endl;

    // User input
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;

    // If-else statement
    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }

    // For loop
    std::cout << "For loop from 1 to 5:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // While loop
    std::cout << "While loop from 5 to 1:" << std::endl;
    int j = 5;
    while (j > 0) {
        std::cout << j << " ";
        --j;
    }
    std::cout << std::endl;

    // Do-while loop
    std::cout << "Do-while loop from 1 to 5:" << std::endl;
    int k = 1;
    do {
        std::cout << k << " ";
        ++k;
    } while (k <= 5);
    std::cout << std::endl;

    return 0;
}