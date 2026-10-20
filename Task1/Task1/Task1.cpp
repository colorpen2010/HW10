#include <iostream>
#include <windows.h>
using namespace std;

int* createArray(int size) {
    return new int[size];
}

void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введіть елемент " << i << ": ";
        cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteArray(int*& arr) {
    delete[] arr;
    arr = 0;
}

void addElement(int*& arr, int& size, int value) {
    int* newArr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    newArr[size] = value;

    delete[] arr;
    arr = newArr;
    size++;
}

void insertElement(int*& arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        cout << "Неправильний індекс!" << endl;
        return;
    }

    int* newArr = new int[size + 1];

    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }

    newArr[index] = value;

    for (int i = index; i < size; i++) {
        newArr[i + 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size++;
}

void removeElement(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Неправильний індекс!" << endl;
        return;
    }

    int* newArr = 0;

    if (size > 1) {
        newArr = new int[size - 1];
    }

    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }

    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size--;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int size;

    cout << "Введіть розмір масиву: ";
    cin >> size;

    if (size <= 0) {
        cout << "Розмір має бути додатним!";
        return 0;
    }

    int* arr = createArray(size);

    initializeArray(arr, size);

    cout << "Початковий масив: ";
    printArray(arr, size);

    int value;
    cout << "Введіть елемент для додавання: ";
    cin >> value;
    addElement(arr, size, value);

    cout << "Після додавання: ";
    printArray(arr, size);

    int index;
    cout << "Введіть індекс для вставки: ";
    cin >> index;
    cout << "Введіть значення: ";
    cin >> value;
    insertElement(arr, size, index, value);

    cout << "Після вставки: ";
    printArray(arr, size);

    cout << "Введіть індекс для видалення: ";
    cin >> index;
    removeElement(arr, size, index);

    cout << "Після видалення: ";
    printArray(arr, size);

    deleteArray(arr);

    return 0;
}