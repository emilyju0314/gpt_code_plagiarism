#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    long long totalScore = 0;
    long long bestScore = 0;
    for (int i = 0; i < n; i++) {
        totalScore += scores[i];
        bestScore = max(bestScore, totalScore - i);
    }

    cout << bestScore << endl;

    return 0;
}