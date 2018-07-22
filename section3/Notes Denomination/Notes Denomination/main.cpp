#include <iostream>
using namespace std;

// GREEDY ALGORITHM

// Task #1
// d - an array listing the denominations in ascending order
// length - length of the array
// amount - required amount that we have to pay
int minimumNotes(int d[], int length, int amount) {
    // We're assuming that the "d" array is sorted

    // Homework: print the notes you're using to pay
    // the required amount
    // For example: 47 = 20 + 20 + 5 + 2

    int notes = 0;

    for (int i = length - 1; i >= 0; i--) {
        while (d[i] <= amount) {
            amount = amount - d[i];
            notes = notes + 1;
        }
    }

    if (amount == 0)
        return notes;
    else return -1;
}

// Task #2
// d - an array listing the denominations in ascending order
// c - an array giving us the number of notes of each type
// length - length of the array
// amount - required amount that we have to pay
int minimumNotes(int d[], int c[], int length, int amount) {
    // Homework
    return -1;
}

int main() {
    int denominations[] =   {1, 2, 5, 10, 20, 50, 100};
    int count[]         =   {0, 2, 10, 5,  0,  1,  10};
    int amount = 47;
    int length = 7;

    cout << minimumNotes(denominations, length, amount) << endl;
    cout << minimumNotes(denominations, count, length, amount) << endl;

    return 0;
}
