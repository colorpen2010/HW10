#include <iostream>
#include <windows.h>
using namespace std;

void separate(int* arr, int size,
    int*& positive, int& positiveSize,
    int*& negative, int& negativeSize,
    int*& zero, int& zeroSize) {

    positiveSize = 0;
    negativeSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            positiveSize++;
        else if (arr[i] < 0)
            negativeSize++;
        else
            zeroSize++;
    }

    positive = new int[positiveSize];
    negative = new int[negativeSize];
    zero = new int[zeroSize];

    int p = 0, n = 0, z = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive[p] = arr[i];
            p++;
        }
        else if (arr[i] < 0) {
            negative[n] = arr[i];
            n++;
        }
        else {
            zero[z] = arr[i];
            z++;
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    if (size == 0)
        cout << "Немає елементів";

    cout << endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    const int M = 8;
    int A[M];

    cout << "Введіть 8 елементів масиву: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    int* positive;
    int* negative;
    int* zero;

    int positiveSize, negativeSize, zeroSize;

    separate(A, M,
        positive, positiveSize,
        negative, negativeSize,
        zero, zeroSize);

    cout << "Додатні числа: ";
    printArray(positive, positiveSize);

    cout << "Від'ємні числа: ";
    printArray(negative, negativeSize);

    cout << "Нулі: ";
    printArray(zero, zeroSize);

    delete[] positive;
    delete[] negative;
    delete[] zero;

    return 0;
}