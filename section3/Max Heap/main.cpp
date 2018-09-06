#include <iostream>
using namespace std;

// Home Work: implement a MinHeap
// implement extractMin
class MaxHeap {
public:
    int *A;
    int length;
    int heapSize;

    MaxHeap(int *data, int n) {
        A = new int[n];
        length = n;
        for (int i = 0; i < n; i++)
            A[i] = data[i];
    }

    ~MaxHeap() {
        delete A;
    }

    // page 157
    void buildMaxHeap() {
        // line 1
        heapSize = length;
        for (int i = length / 2; i >= 0; i--)
            maxHeapify(i);
    }

    int parent(int i) {
        return i / 2;
    }

    int left(int i) {
        return 2 * i;
    }

    int right(int i) {
        return 2 * i + 1;
    }

    void maxHeapify(int i) {
        int l = left(i);
        int r = right(i);

        int largest;

        if (l < heapSize && A[l] > A[i])
            largest = l;
        else largest = i;

        if (r < heapSize && A[r] > A[largest])
            largest = r;

        if (largest != i) {
            int temp = A[i];
            A[i] = A[largest];
            A[largest] = temp;
            maxHeapify(largest);
        }

    }

    void print() {
        for (int i = 0; i < length; i++)
            cout << A[i] << " ";
        cout << endl;
    }
};

int main() {
    int data[] = {5, 2, 1, 6, 34, 7, 2, 6, 19};
    int n = 9;

    MaxHeap h(data, n);
    h.print();
    h.buildMaxHeap();
    h.print();

    return 0;
}
