#include <iostream>
using namespace std;

const int INF = 1000000;

void printArray(int A[], int p, int r) {
    for (int i = p; i <= r; i++)
        cout << i << ":" << A[i] << " ";
    cout << endl;
}

/*
Homework: test this mergesort implementation
against insertion sort and selection sort
*/
void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // static declaration
    int L[n1 + 1];
    int R[n2 + 1];

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
}

void mergeSort(int A[], int p, int r) {
    if (p < r) {
        //printArray(A, p, r);
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int data[] ={52, 12, 16, 66, 34, 12, 99, 44, 57, 61};
    mergeSort(data, 0, 9);
    printArray(data, 0, 9);
    return 0;
}
