#include <iostream>
#include <cstdlib>
using namespace std;

const int INF = 1000000;

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

void insertionSort(int A[], int p, int r) {
    for (int j = p + 1; j < r + 1; j++) {
        int key = A[j];
        int i = j - 1;
        while (i > -1 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // static declaration
//    int L[n1 + 1];
    //int R[n2 + 1];

    // dynamic declaration
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    L[n1] = INF;
    R[n2] = INF;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }

    delete L;
    delete R;
}

const int K = 2;
void mergeSort(int A[], int p, int r) {
    int length = r - p + 1;
    if (length > K ) {
        //printArray(A, p, r);
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    } else {
        insertionSort(A, p, r);
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
    int N = 19000000;
    //int N = 1000;
//    int data[N];
    int *data = new int[N]; // in C++
//    int *data = (int*) malloc(N * sizeof(int)); // in C

    generateArray(data, N);
    cout << "Generated an array of " << N << " elements" << endl;
    cout << "Started sorting" << endl;

    clock_t start = clock();
    mergeSort(data, 0, N - 1);
    //insertionSort(data, 0, N - 1);
    clock_t stop = clock();

    cout << "Done sorting" << endl;

    long timeDifference = stop - start;
    double timeTaken = (double) timeDifference / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << endl;

    cout << "Sorted: " << isAscending(data, N);
    cout << endl;

    delete data; // in C++
    //free(data); // in C

    return 0;
}
