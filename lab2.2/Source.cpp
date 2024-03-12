#include <iostream>
#include "IntegerSet.h"

int main() {
    // Створення множини A {1, 2, 3}
    int arrA[] = { 1, 2, 3 };
    IntegerSet A(arrA, 3);

    // Створення множини B {3, 4, 5}
    int arrB[] = { 3, 4, 5 };
    IntegerSet B(arrB, 3);

    // Вивід множин A та B
    std::cout << "Set A: " << A << std::endl;
    std::cout << "Set B: " << B << std::endl;

    // Об'єднання множин A та B
    IntegerSet unionSet = A + B;
    std::cout << "Union of A and B: " << unionSet << std::endl;

    // Різниця множин A та B
    IntegerSet differenceSet = A - B;
    std::cout << "Difference of A and B: " << differenceSet << std::endl;

    // Перетин множин A та B
    IntegerSet intersectionSet = A * B;
    std::cout << "Intersection of A and B: " << intersectionSet << std::endl;

    // Введення нової множини з клавіатури
    IntegerSet C;
    std::cout << "Enter elements of set C (separated by space): ";
    std::cin >> C;
    std::cout << "Set C: " << C << std::endl;

    std::cout << C.toString() << std::endl;

    IntegerSet D;
    std::cout << "Enter elements of set D (separated by space): ";
    std::cin >> D;
    std::cout << "Set D: " << D << std::endl;

    IntegerSet differenceSet1 = C - D;
    std::cout << "Difference of C and D: " << differenceSet1 << std::endl;

    return 0;
}
