#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cards(n);
    vector<int> frontOccurrences(2*n+1, 0), backOccurrences(2*n+1, 0);
    vector<int> minFlips(2*n+1, n); // Initialize all elements with n

    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second;
        frontOccurrences[cards[i].first] = i+1;
        backOccurrences[cards[i].second] = i+1;
    }

    for (int i = 1; i <= 2*n; i++) {
        if (frontOccurrences[i] == 0 || backOccurrences[i] == 0) { // Element missing
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        minFlips[i+1] = min(minFlips[i+1], minFlips[frontOccurrences[i+1]-1] + (frontOccurrences[i+1] > 1 && backOccurrences[frontOccurrences[i+1]-1] > backOccurrences[frontOccurrences[i+1]]));
        minFlips[i+1] = min(minFlips[i+1], minFlips[backOccurrences[i+1]-1] + (backOccurrences[i+1] > 1 && frontOccurrences[backOccurrences[i+1]-1] > frontOccurrences[backOccurrences[i+1]]));
    }

    cout << minFlips[n] << endl;

    return 0;
}