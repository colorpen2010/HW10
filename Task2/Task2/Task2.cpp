#include <iostream>
#include <windows.h>
using namespace std;

bool isPrime(int number) {
    if (number < 2)
        return false;

    for (int i = 2; i < number; i++) {
        if (number % i == 0)
            return false;
    }

    return true;
}

int* removePrimes(int* arr, int size, int& newSize) {
    newSize = 0;

    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[j] = arr[i];
            j++;
        }
    }

    return newArr;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int size;

    cout << "Введіть розмір масиву: ";
    cin >> size;

    if (size <= 0) {
        cout << "Неправильний розмір!";
        return 0;
    }

    int* arr = new int[size];

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int newSize;
    int* newArr = removePrimes(arr, size, newSize);

    delete[] arr;
    arr = newArr;
    size = newSize;

    cout << "Масив без простих чисел: ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    if (size == 0)
        cout << "Масив порожній";

    delete[] arr;

    return 0;
}