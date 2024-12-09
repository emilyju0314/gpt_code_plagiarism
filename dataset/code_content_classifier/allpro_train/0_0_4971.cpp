#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int matches[n];
    int totalMatches = 0;

    for (int i = 0; i < n; i++) {
        cin >> matches[i];
        totalMatches += matches[i];
    }

    int averageMatches = totalMatches / n;
    int moves = 0;

    for (int i = 0; i < n; i++) {
        int diff = matches[i] - averageMatches;
        if (diff > 0) {
            matches[i + 1] += diff;
            moves += diff;
        }
    }

    cout << moves << endl;

    return 0;
}