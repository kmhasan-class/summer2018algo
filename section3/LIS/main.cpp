#include <iostream>
using namespace std;

// HW: try the other two tasks

int max(int x, int y) {
    if (x > y)
        return x;
    else return y;
}

int lengthLIS(int A[], int length) {
    int *L = new int[length];

    int maxLength = 1;
    for (int i = 0; i < length; i++) {
        L[i] = 1;
        // need to fix the starting index
        for (int j = 1; j <= i - 1; j++)
            if (A[i] > A[j]) {
                L[i] = max(L[i], L[i] + 1);
                maxLength = max(L[i], maxLength);
            }
    }

    delete L;

    return maxLength;
}

int main() {
    int N = 16;
    int sequence[] = {6, 8, 2, 4, 5, 10, 6, 23, 45, 3, 4, 9, 12, 13, 30, 4};
    //cout << "N = " << sizeof(sequence) / sizeof(int) << endl;
    int length = lengthLIS(sequence, N);
    cout << length << endl;
}
