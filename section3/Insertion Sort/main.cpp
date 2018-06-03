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

int main() {
/*
H/W #1: Try this program with different values of
n. n = 1, 10, 100, ... , up to 10 million
Run the program multiple times for each n value
Write them down on a table (on spreadsheet) or on paper

H.W #2: Implement bubble sort and run the same
experiments and tabulate your findings
*/
    int n = 100000;
//    int array[n]; // static allocation
    int *array1 = new int[n]; // dynamic allocation
    generateArray(array1, n);

    int *array2 = new int[n];
    for (int i = 0; i < n; i++)
        array2[i] = array1[i];

//    cout << "Before sorting: ";
//    printArray(array, n);

    // Selection Sort
    clock_t start = clock();
    selectionSort(array1, n);
    clock_t stop = clock();

//    cout << "After sorting:  ";
//    printArray(array, n);

    long clockTicks = stop - start;
    cout << "Algorithm: Selection Sort" << endl;
    cout << "n = " << n << endl;
    cout << "clock ticks = " << clockTicks << endl;
    cout << "clocks per sec = " << CLOCKS_PER_SEC << endl;
    double timeTaken = (double) clockTicks / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << " seconds " << endl;

//    cout << "Before sorting: ";
//    printArray(array, n);

    // Insertion Sort
    start = clock();
    insertionSort(array1, n);
    stop = clock();

//    cout << "After sorting:  ";
//    printArray(array, n);

    cout << endl;

    clockTicks = stop - start;
    cout << "Algorithm: Insertion Sort" << endl;
    cout << "n = " << n << endl;
    cout << "clock ticks = " << clockTicks << endl;
    cout << "clocks per sec = " << CLOCKS_PER_SEC << endl;
    timeTaken = (double) clockTicks / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << " seconds " << endl;

}
