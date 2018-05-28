#include <iostream>
using namespace std;

void printArray(int A[], int length) {
    for (int i = 0; i < length; i++) {
        if (i != 0)
            cout << ", ";
        cout << A[i];
    }
    cout << endl;
}

void generateArray(int A[], int length) {
// WRITE YOUR CODE HERE
}

void insertionSort(int A[], int length) {
    for (int j = 1; j < length; j++) {
        int key = A[j];
        int i = j - 1;
        while (i > -1 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

int main() {
    // Homework
    // set n = 10000
    // generate n random numbers
    // to fill out the array
    // Hint: use srand and random
    // functions from cstdlib header
    // generateArray(array, 10000);
    int array[] = {56, 88, 32, 21, 14, 100, 56, 32, 19};
    int n = 9;

    cout << "Before sorting: ";
    printArray(array, n);

    // Insertion Sort
    insertionSort(array, n);

    cout << "After sorting:  ";
    printArray(array, n);

}
