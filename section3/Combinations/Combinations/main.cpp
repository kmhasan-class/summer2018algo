#include <iostream>
using namespace std;

long c(long n, long r) {
    if (r == 0 || n == r)
        return 1;
    else return c(n - 1, r - 1) + c(n - 1, r);
}

// 1. Memoization
const int MAXN = 50001;
long **TABLE;

void allocateArray() {
    TABLE = new long*[MAXN];
    for (int r = 0; r < MAXN; r++)
        TABLE[r] = new long[r + 1];
/*
    for (int r = 0; r < MAXN; r++)
        for (int c = 0; c < MAXN; c++)
            TABLE[r][c] = 0;
            */
}

void freeArray() {
    for (int r = 0; r < MAXN; r++)
        delete TABLE[r];
    delete TABLE;
}

long c1(long n, long r) {
    if (r == 0 || n == r)
        return 1;
    else {
        if (TABLE[n][r] > 0)
            return TABLE[n][r];
        TABLE[n][r] = c1(n - 1, r - 1) + c1(n - 1, r);
        return TABLE[n][r];
    }
}

// 2. Dynamic Programming
long c2(long n, long r) {
    for (int row = 0; row <= n; row++) {
        TABLE[row][0] = 1;
        TABLE[row][row] = 1;
    }

    for (int row = 2; row <= n; row++)
        for (int col = 1; col <= r; col++)
            TABLE[row][col] = TABLE[row - 1][col - 1] + TABLE[row - 1][col];

    return TABLE[n][r];
}

int main() {
    allocateArray();
    cout << c(4, 2) << endl;
    cout << c1(50000, 2) << endl;
    cout << c2(50000, 2) << endl;
    freeArray();
    return 0;
}
