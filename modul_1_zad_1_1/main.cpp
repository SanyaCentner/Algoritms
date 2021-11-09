#include <iostream>

int size_of_bite(int number) {
    unsigned int res = 0;
    while (number > 0) {
        if ((number & 1) > 0)
            ++res;
        number = number >> 2;
    }
    return res;
}

int main() {
    std::cout << "Введите число:\n";
    int number;
    std::cin >> number;
    std::cout << size_of_bite(number);
    return 0;
}
