#include <iostream>
#include <cstdlib>
using namespace std;

const int INF = 10000000;

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

//    int L[n1 + 1];
//    int R[n2 + 1];
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

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
    }

    delete L;
    delete R;
}

// page 34
const int K = 2;
void mergeSort(int A[], int p, int r) {
    if (p < r - K) {
        //printArray(A, p, r);
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    } else {
        insertionSort(A, p, r);
    }
}

int main() {
    int N = 17000000;

    int *data = new int[N];
    //int data[N];

    generateArray(data, N);

    cout << "Generated a random array of " << N << " elements" << endl;
    cout << "Started sorting" << endl;
    clock_t start = clock();
    mergeSort(data, 0, N - 1);
    clock_t stop = clock();
    cout << "Done with sorting" << endl;
    long clockTicks = stop - start;
    double timeTaken = (double) clockTicks / CLOCKS_PER_SEC;
    cout << "time taken " << timeTaken << " seconds " << endl;

    delete data;

    return 0;
}
