#include "IntegerSet.h"

std::string IntegerSet::toString() const {
    std::stringstream ss;
    ss << "{ ";
    for (int i = 0; i < size; ++i)
        ss << elements[i] << " ";
    ss << "}";
    return ss.str();
}

// Операції введення-виведення
std::istream& operator>>(std::istream& in, IntegerSet& set) {
    std::string line;
    getline(in, line);
    std::istringstream iss(line);
    int num;
    while (iss >> num)
        set.add(num);
    return in;
}

std::ostream& operator<<(std::ostream& out, const IntegerSet& set) {
    out << "{ ";
    for (int i = 0; i < set.size; ++i)
        out << set.elements[i] << " ";
    out << "}";
    return out;
}

// Методи для роботи з елементами множини
bool IntegerSet::contains(int num) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == num)
            return true;
    }
    return false;
}

void IntegerSet::add(int num) {
    if (!contains(num)) {
        int* newArr = new int[size + 1];
        for (int i = 0; i < size; ++i)
            newArr[i] = elements[i];
        newArr[size] = num;
        delete[] elements;
        elements = newArr;
        ++size;
    }
}

IntegerSet IntegerSet::operator+(const IntegerSet& other) const {
    int newSize = size + other.size;
    int* newArr = new int[newSize];

    // Копіюємо елементи поточної множини
    for (int i = 0; i < size; ++i)
        newArr[i] = elements[i];

    // Додаємо елементи з іншої множини
    int j = size;
    for (int i = 0; i < other.size; i++) {
            newArr[j] = other.elements[i];
            j++;
    }

    IntegerSet result(newArr, newSize);
    delete[] newArr;
    return result;
}

IntegerSet IntegerSet::operator-(const IntegerSet& other) const {
    int* newArr = new int[size];
    int newSize = 0;

    // Копіюємо елементи, які не належать іншій множині
    for (int i = 0; i < size; ++i) {
        if (!other.contains(elements[i])) {
            newArr[newSize] = elements[i];
            ++newSize;
        }
    }

    IntegerSet result(newArr, newSize);
    delete[] newArr;
    return result;
}

IntegerSet IntegerSet::operator*(const IntegerSet& other) const {
    int* newArr = new int[size];
    int newSize = 0;

    // Копіюємо елементи, які належать іншій множині
    for (int i = 0; i < size; ++i) {
        if (other.contains(elements[i])) {
            newArr[newSize] = elements[i];
            ++newSize;
        }
    }

    IntegerSet result(newArr, newSize);
    delete[] newArr;
    return result;
}

IntegerSet IntegerSet::operator=(const IntegerSet& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new int[size];
        for (int i = 0; i < size; ++i)
            elements[i] = other.elements[i];
    }
    return *this;
}
