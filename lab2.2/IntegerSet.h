#pragma once
#include <iostream>
#include <sstream>
#include <string>

class IntegerSet {
private:
    int* elements; // Вказівник на динамічний масив
    int size;      // Розмір масиву

public:
    void setSize(int s) { size = s; };
    int getSize() const { return size; };

    void setElements(int* el) { elements = el; };
    int* getElements() { return elements; };

    std::string toString() const;

    // Конструктори
    IntegerSet() : elements(nullptr), size(0) {};
    IntegerSet(const int arr[], int n) : size(n) {
        elements = new int[size];
        for (int i = 0; i < size; ++i)
            elements[i] = arr[i];
    }

    IntegerSet(const IntegerSet& other) : size(other.size) {
        elements = new int[size];
        for (int i = 0; i < size; ++i)
            elements[i] = other.elements[i];
    }

    // Деструктор для звільнення пам'яті
    ~IntegerSet() {
        delete[] elements;
    };

    // Операції
    IntegerSet operator+(const IntegerSet& other) const;
    IntegerSet operator-(const IntegerSet& other) const;
    IntegerSet operator*(const IntegerSet& other) const;
    IntegerSet operator=(const IntegerSet& other);
    friend std::istream& operator>>(std::istream& in, IntegerSet& set);
    friend std::ostream& operator<<(std::ostream& out, const IntegerSet& set);
    bool contains(int num) const;
    void add(int num);
};