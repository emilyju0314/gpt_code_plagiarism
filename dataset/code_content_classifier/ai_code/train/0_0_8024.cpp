#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end(), greater<int>());

    int ways = 1;
    int currentScore = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] != 0 && scores[i] >= currentScore) {
            ways++;
            currentScore = scores[i];
        }
    }

    cout << ways << endl;

    return 0;
}