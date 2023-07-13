#include <iostream>
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* elements;
    size_t capacity;
    size_t size;

public:
    Vector() : elements(nullptr), capacity(0), size(0) {}

    ~Vector() {
        delete[] elements;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            // If the vector is full, increase its capacity
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }
            T* newElements = new T[capacity];
            
            // Copy existing elements to the new array
            for (size_t i = 0; i < size; i++) {
                newElements[i] = elements[i];
            }

            // Free the memory occupied by the old array
            delete[] elements;
            
            // Update the pointer to the new array
            elements = newElements;
        }

        // Add the new element at the end of the vector
        elements[size++] = value;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }
};

int main() {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Vector size: " << vec.getSize() << std::endl;
    std::cout << "Vector capacity: " << vec.getCapacity() << std::endl;

    for (size_t i = 0; i < vec.getSize(); i++) {
        std::cout << "Element at index " << i << ": " << vec[i] << std::endl;
    }

    return 0;
}
