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
        A[i] = random() % 100;
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
    // A[] = {3, 5, 5, 7, 8, 12, 9, 10}
    // A[] = {3, 5, 5, 7, 8, 9, 10, 12}
    for (int i = 0; i < n - 1; i++)
        if (A[i] > A[i + 1])
            return false;
    return true;
}

int main() {
/*
H/W #1: Try this program with different values of
n. n = 1, 10, 100, ... , up to 10 million
Run the program multiple times for each n value
Write them down on a table (on spreadsheet) or on paper

H.W #2: Implement bubble sort and run the same
experiments and tabulate your findings
*/
    int n = 10;
//    int array[n]; // static allocation
    int *array1 = new int[n]; // dynamic allocation
    generateArray(array1, n);

    insertionSort(array1, n);
    for (int i = 0; i < n / 2; i++) {
        int j = n - i - 1;
        int temp = array1[i];
        array1[i] = array1[j];
        array1[j] = temp;
    }

    int *array2 = new int[n];
    for (int i = 0; i < n; i++)
        array2[i] = array1[i];

    cout << "Before sorting: ";
    printArray(array1, n);

    // Selection Sort
    clock_t start = clock();
    selectionSort(array1, n);
    clock_t stop = clock();

    cout << "After sorting:  ";
    printArray(array1, n);

    long clockTicks = stop - start;
    cout << "Algorithm: Selection Sort" << endl;
    cout << "n = " << n << endl;
    cout << "clock ticks = " << clockTicks << endl;
    cout << "clocks per sec = " << CLOCKS_PER_SEC << endl;
    double timeTaken = (double) clockTicks / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << " seconds " << endl;
    if (isAscending(array1, n)) {
        cout << "Array elements are in ascending order" << endl;
    } else {
        cerr << "Array elements are NOT in ascending order" << endl;
    }

    cout << endl;

    cout << "Before sorting: ";
    printArray(array2, n);

    // Insertion Sort
    start = clock();
    insertionSort(array2, n);
    stop = clock();

    cout << "After sorting:  ";
    printArray(array2, n);

    clockTicks = stop - start;
    cout << "Algorithm: Insertion Sort" << endl;
    cout << "n = " << n << endl;
    cout << "clock ticks = " << clockTicks << endl;
    cout << "clocks per sec = " << CLOCKS_PER_SEC << endl;
    timeTaken = (double) clockTicks / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << " seconds " << endl;

    if (isAscending(array2, n)) {
        cout << "Array elements are in ascending order" << endl;
    } else {
        cerr << "Array elements are NOT in ascending order" << endl;
    }

}
