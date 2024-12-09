#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> difficulties(m);
    for (int i = 0; i < m; i++) {
        cin >> difficulties[i];
    }

    unordered_map<int, int> freq;
    int distinct = 0;
    vector<int> result(m);

    for (int i = 0; i < m; i++) {
        int difficulty = difficulties[i];
        freq[difficulty]++;
        if (freq[difficulty] == 1) distinct++;
        if (distinct == n) {
            result[i] = 1;
            distinct = 0;
            freq.clear();
        } else {
            result[i] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << result[i];
    }

    return 0;
}