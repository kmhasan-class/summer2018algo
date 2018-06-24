#include <iostream>
#include <cstdlib>
using namespace std;

/*
H.W.
#1 Modify this linear search to return the first index
(leftmost) where the key is found
#2 Modify this linear search to return all the indexes where
this particular key can be found
*/
int linearSearch(int A[], int length, int key) {
    int index = -1;

    for (int j = 0; j < length; j++)
        if (A[j] == key)
            index = j;

    return index;
}

void generateArray(int A[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        A[i] = random() % 100;
    }
}

int main() {
/*
    int array[] = {67, 23, 34, 99, 78, 42, 67, 77};
    int n = 8;
    int key = 67;
*/
    int n = 100000;
    int *array = new int[n];
    generateArray(array, n);

    for (int i = 0; i < 100; i++) {
        cout << "Test #" << i + 1 << endl;

        int key = random() % 100;

        cout << "Searching for " << key << " ... " << endl;

        int index = linearSearch(array, n, key);

        if (index >= 0) {
            cout << "Found " << key << " at " << index << endl;
        } else {
            cout << key << " not found!" << endl;
        }

        cout << endl;
    }

    return 0;
}
