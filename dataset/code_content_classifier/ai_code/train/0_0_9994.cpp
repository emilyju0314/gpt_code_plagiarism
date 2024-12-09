#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rounds(n);
    int totalRounds = 0;
    for (int i = 0; i < n; i++) {
        cin >> rounds[i];
        totalRounds += rounds[i];
    }

    int maxRounds = *max_element(rounds.begin(), rounds.end());

    if (maxRounds * n - totalRounds <= totalRounds) {
        cout << maxRounds << endl;
    } else {
        cout << (totalRounds + n - 1) / n << endl;
    }

    return 0;
}