#include <iostream>
using namespace std;

// GREEDY Algorithm

// Homework: come up with an example for which this algorithm
// gives you wrong answer
int minimumNotes(int denomination[], int length, int amount) {
    int notes = 0;
    // Homework: instead of returning the number of notes
    // give us the denominations used
    // Example: 47 = 20 + 20 + 5 + 2
    for (int i = length - 1; i >= 0; i--) {
        // Homework: use mod and div to make this code
        // efficient
        while (denomination[i] <= amount) {
            amount = amount - denomination[i];
            notes = notes + 1;
        }
    }
    if (amount == 0)
        return notes;
    else return -1;
}

// Homework: come up with an example for which this algorithm
// gives you wrong answer
int minimumNotes(int denomination[], int count[], int length, int amount) {
    int notes = 0;
    for (int i = length - 1; i >= 0; i--) {
        while (denomination[i] <= amount && count[i] > 0) {
            amount = amount - denomination[i];
            notes = notes + 1;
            count[i] = count[i] - 1;
        }
    }
    if (amount == 0)
        return notes;
    else return -1;
}

int main() {
    int length = 7;
    int denomination[]  =   {1, 2, 5, 10, 20, 50, 100};
    int count[]         =   {2,10, 1,  0,  1,  2,   3};
    int amount = 47;

    cout << minimumNotes(denomination, length, amount) << endl;
    cout << minimumNotes(denomination, count, length, amount) << endl;
}
