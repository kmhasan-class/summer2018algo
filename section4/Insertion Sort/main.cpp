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
    int n = 1000000;
    int *array = new int[n]; //dynamic allocation
    generateArray(array, n);

    //int n = sizeof(array) / sizeof(array[0]);

//    cout << "Before sorting: ";
//    printArray(array, n);

    // insertion sort
    clock_t start = clock();
    insertionSort(array, n);
    clock_t stop = clock();

    long timeDifference = stop - start;
    cout << "n = " << n << endl;
    double timeTaken = (double) timeDifference / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << endl;
//    cout << "After sorting:  ";
//    printArray(array, n);

    return 0;
}
