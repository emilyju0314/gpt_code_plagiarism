#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<long long> numbers(m);
    for (int i = 0; i < m; i++) {
        cin >> numbers[i];
    }

    vector<unordered_map<long long, int>> xorSums(m + 1);
    vector<bool> used(m, false);

    for (int i = 0; i < m; i++) {
        xorSums[0][0] = 0;
        int k = -1;
        long long xorSum = 0;
        
        for (int j = 0; j < m; j++) {
            if (!used[j] && xorSums[j].count(xorSum ^ numbers[i])) {
                k = j;
                break;
            }
        }

        if (k == -1) {
            cout << 0 << endl;
        } else {
            int count = 0;
            int idx = i;
            while (idx != k) {
                used[idx] = true;
                count++;
                xorSum ^= numbers[idx];
                idx = xorSums[idx][xorSum ^ numbers[idx]];
            }
            used[k] = true;
            count++;
            xorSum ^= numbers[k];

            cout << count;
            for (idx = i; idx != k; idx = xorSums[idx][xorSum ^ numbers[idx]]) {
                cout << " " << idx;
            }
            cout << " " << k << endl;
        }
    }

    return 0;
}