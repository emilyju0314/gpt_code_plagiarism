#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> firstPerm(n);
    unordered_map<int, int> firstIndex;
    for (int i = 0; i < n; i++) {
        cin >> firstPerm[i];
        firstIndex[firstPerm[i]] = i + 1;
    }

    vector<int> secondPerm(n);
    for (int i = 0; i < n; i++) {
        cin >> secondPerm[i];
    }

    int moves = 0;
    int maxMoveEnd = 0;

    for (int i = 0; i < n; i++) {
        if (firstIndex[secondPerm[i]] < maxMoveEnd) {
            moves++;
        } else {
            maxMoveEnd = firstIndex[secondPerm[i]];
        }
    }

    cout << moves << endl;

    return 0;
}