#include <iostream>
using namespace std;

bool icecreamParlorProblem(int A[], int length, int money) {
    for (int j = 0; j < length; j++) {
        int remaining = money - A[j];
        for (int i = j + 1; i < length; i++)
            if (A[i] == remaining)
                return true;
    }
    return false;
}

int main() {
    int cost[] = {100, 120, 110, 120, 150};
    int amountToSpend = 300;

    bool result = icecreamParlorProblem(cost, 5, amountToSpend);

    cout << result << endl;

    return 0;
}
