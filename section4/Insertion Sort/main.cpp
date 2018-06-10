#include <iostream>
#include <cstdlib>
#include <ctime>
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
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int number = random() % 100;
        A[i] = number;
    }
}

void selectionSort(int A[], int length) {
    for (int j = 0; j < length - 1; j++) {
        int minIndex = j;
        for (int i = j + 1; i < length; i++)
            if (A[i] < A[minIndex])
                minIndex = i;
        if (minIndex != j) {
            int temp = A[j];
            A[j] = A[minIndex];
            A[minIndex] = temp;
        }
    }
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

bool isAscending(int A[], int n) {
    // WRITE YOUR CODE HERE
    // 2, 3, 5, 6, 7, 7, 34, 21
    // 0  1  2  3  4  5   6   7
    for (int i = 0; i < n - 1; i++)
        if (A[i] > A[i + 1])
            return false;
    return true;
}

int main() {
// H/W #1:
// Calculate a table to see how much time
// it takes to do insertion sort for
// n = 1, 10, 100 ..., up to 10 million numbers
// try to run the program multiple times
// to find out the time taken and then calculate
// the average time for the given n value

// H/W #2:
// implement bubble sort and run the same
// experiments
    int n = 10;
    int *array1 = new int[n]; //dynamic allocation
    generateArray(array1, n);
    int *array2 = new int[n];
    insertionSort(array1, n);
//    for (int i = 0; i < n; i++)
//        array2[i] = array1[i];
    for (int i = 0; i < n; i++)
        array2[n - 1 - i] = array1[i];
    for (int i = 0; i < n; i++)
        array1[i] = array2[i];

    //int n = sizeof(array) / sizeof(array[0]);

//    cout << "Before sorting: ";
    //printArray(array1, n);

    // Selection sort
    clock_t start = clock();
    selectionSort(array1, n);
    clock_t stop = clock();

    //cout << "After sorting:  ";
    //printArray(array1, n);

    long timeDifference = stop - start;
    cout << "Selection sort" << endl;
    cout << "n = " << n << endl;
    double timeTaken = (double) timeDifference / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << endl;

    cout << endl;

    cout << "Before sorting: ";
    printArray(array2, n);

    // Insertion sort
    start = clock();
    insertionSort(array2, n);
    stop = clock();

    cout << "After sorting:  ";
    printArray(array2, n);

    timeDifference = stop - start;
    cout << "Insertion sort" << endl;
    cout << "n = " << n << endl;
    timeTaken = (double) timeDifference / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << endl;
    if (isAscending(array2, n))
        cout << "The elements are in ascending order" << endl;
    else cout << "The elements are NOT in ascending order" << endl;

    return 0;
}
