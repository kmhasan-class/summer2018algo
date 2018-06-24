#include <iostream>
#include <cstdlib>
using namespace std;

/*
H.W.
#1 Modify this binary search to return the first index
(leftmost) where the key is found
#2 Modify this binary search to return all the indexes where
this particular key can be found
*/
int binarySearch(int A[], int length, int key) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == key)
            return mid;
        if (A[mid] < key)
            low = mid + 1;
        else high = mid - 1;
    }

    return -1;
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

    int n = 8;
    int array[] = {67, 67, 67, 72, 73, 77, 78, 99};
    //int key = 43;

/*
    int n = 100000;
    int *array = new int[n];
    generateArray(array, n);
    insertionSort(array, n);
*/
//    for (int i = 0; i < 100; i++) {
        int key = 67;

        int index = binarySearch(array, n, key);

        if (index < 0) {
            cout << key << " not found!" << endl;
        } else {
            cout << "Found " << key << " at index " << index << endl;
        }
//    }

    return 0;
}
