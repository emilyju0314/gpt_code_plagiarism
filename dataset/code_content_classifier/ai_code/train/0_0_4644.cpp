#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> powers; // pair of (power, index)
        for (int j = 0; j < k; j++) {
            int power;
            cin >> power;
            powers.push_back({power, j});
        }
        sort(powers.begin(), powers.end());

        int winners = 1;
        for (int j = 1; j < k; j++) {
            if (powers[j].first > powers[0].first) {
                winners = j + 1;
            }
        }

        cout << winners << endl;
    }

    return 0;
}