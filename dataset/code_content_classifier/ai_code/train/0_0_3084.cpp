#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> powers(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> powers[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int winners = 1;
        for (int j = 0; j < i; j++) {
            int count = 0;
            for (int l = 0; l < k; l++) {
                if (powers[i][l] < powers[j][l]) {
                    count++;
                }
            }
            if (count != k) {
                winners++;
            }
        }
        cout << winners << endl;
    }

    return 0;
}