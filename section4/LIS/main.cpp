#include <iostream>
using namespace std;

int max(int x, int y) {
    if (x > y)
        return x;
    else return y;
}

// HW: task 2 and task 3

int lengthLIS(int A[], int length) {
    int maxLength = 0;

    int *L = new int[length];

    for (int i = 0; i < length; i++) {
        L[i] = 1;
        for (int j = 0; j <= i - 1; j++)
            if (A[i] > A[j]) {
                L[i] = max(L[i], 1 + L[j]);
                maxLength = max(L[i], maxLength);
            }
    }

    delete L;

    return maxLength;
}

int main() {
    int N = 8;
    int sequence[] = {8, 4, 12, 5, 6, 9, 3, 7};
//    int N = 0;
//    int sequence[] = {};
    int length = lengthLIS(sequence, N);
    cout << length << endl;
    return 0;
}
