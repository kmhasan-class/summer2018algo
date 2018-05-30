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
    int n = 200000;
//    int array[n]; // static allocation
    int *array = new int[n]; // dynamic allocation
    generateArray(array, n);

//    cout << "Before sorting: ";
//    printArray(array, n);

    // Insertion Sort
    clock_t start = clock();
    insertionSort(array, n);
    clock_t stop = clock();

    long clockTicks = stop - start;
    cout << "n = " << n << endl;
    cout << "clock ticks = " << clockTicks << endl;
    cout << "clocks per sec = " << CLOCKS_PER_SEC << endl;
    double timeTaken = (double) clockTicks / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << " seconds " << endl;
    //cout << "After sorting:  ";
    //printArray(array, n);

}
