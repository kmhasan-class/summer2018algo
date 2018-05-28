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
    int n = 6;
    int array[] = {65, 32, 114, 52, 19, 80};
    //int n = sizeof(array) / sizeof(array[0]);

    cout << "Before sorting: ";
    printArray(array, n);

    // insertion sort
    insertionSort(array, n);

    cout << "After sorting:  ";
    printArray(array, n);

    return 0;
}
