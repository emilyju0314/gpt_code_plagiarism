#include <iostream>
#include <vector>

using namespace std;

bool isCool(long long x, long long y) {
    if (2 * x % y != 0) {
        return false;
    }
    long long sum = 2 * x / y;
    if (sum % 2 == 1 && y % 2 == 1) {
        return true;
    }
    if (sum % 2 == 0 && y % 2 == 0) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<long long> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int minMoves = 0;
    for (int i = 1; i < n; i++) {
        if (!isCool(sequence[i], i+1)) {
            minMoves++;
        }
    }

    cout << minMoves << endl;

    return 0;
}