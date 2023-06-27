// Pass by reference example
void modifyByReference(int& num) {
    num += 10;
}

int main() {
    int value = 5;
    modifyByReference(value);
    // The value is modified directly
    // value is now 15
    return 0;
}

// Pass by pointer example
void modifyByPointer(int* numPtr) {
    (*numPtr) += 10;
}

int main() {
    int value = 5;
    modifyByPointer(&value);
    // The value is modified via a pointer
    // value is now 15
    return 0;
}
