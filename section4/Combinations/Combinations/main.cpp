#include <iostream>
using namespace std;

// Basic Recursion
// based on our recurrence relation
long C(long n, long r) {
    if (n == r || r == 0)
        return 1;
    else return C(n - 1, r - 1) + C(n - 1, r);
}

// Memoization
// Top down approach
const int MAXN = 60000;
long **TABLE;
long C1(long n, long r) {
    if (n == r || r == 0)
        return 1;
    if (TABLE[n][r] > 0)
        return TABLE[n][r];
    else {
        TABLE[n][r] = C1(n - 1, r - 1) + C1(n - 1, r);
        return TABLE[n][r];
    }
}

// Dynamic Programming
// Bottom up approach
long C2(long n, long r) {
    for (long row = 0; row <= n; row++) {
        TABLE[row][0] = 1;
        TABLE[row][row] = 1;
    }

    for (long row = 2; row <= n; row++)
        for (long col = 1; col <= r; col++)
            TABLE[row][col] = TABLE[row - 1][col - 1] + TABLE[row - 1][col];

    return TABLE[n][r];
}

// HW: find the recurrence for nPr

int main() {
    TABLE = new long*[MAXN];
    for (int i = 0; i < MAXN; i++)
        TABLE[i] = new long[MAXN];

    cout << C(4, 2) << endl;
    cout << C2(50000, 2) << endl;

    for (int i = 0; i < MAXN; i++)
        delete TABLE[i];
    delete TABLE;

    return 0;
}
