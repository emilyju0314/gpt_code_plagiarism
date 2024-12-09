#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> count;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        count[color]++;
    }

    int maxStreak = 0;
    int currentMax = 0;

    for (auto it : count) {
        freq[it.second]++;
        currentMax = max(currentMax, freq[it.second]);
        maxStreak = max(maxStreak, currentMax * it.second);
    }

    cout << maxStreak << endl;

    return 0;
}