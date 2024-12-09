#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> schedule(k, vector<int>(m));

        int count = 1;
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                if (count > n) {
                    schedule[j][l] = 0;
                } else {
                    schedule[j][l] = count;
                    count++;
                }
            }
        }

        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                if (schedule[j][m - 1] == 0 && l != m - 1) {
                    cout << m - 1 << " ";
                } else {
                    cout << m << " ";
                }
            }
            cout << endl;

            for (int l = 0; l < m; l++) {
                if (schedule[j][l] != 0) {
                    cout << schedule[j][l] << " ";
                }
            }
            cout << endl;
        }

        if (i != t - 1) {
            cout << endl;
        }
    }

    return 0;
}