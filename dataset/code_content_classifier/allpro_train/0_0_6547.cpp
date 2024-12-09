#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int q;
    cin >> q;

    while (q--) {
        string b;
        cin >> b;

        vector<int> ways(m + 1, 0);
        ways[0] = 1;

        for (int i = 0; i < n; i++) {
            vector<int> new_ways(m + 1, 0);

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= m; k++) {
                    int diff = 0;
                    for (int l = 0; l < m; l++) {
                        if (j + (b[l] - 'a') >= m) {
                            diff += (strings[i][l] - 'a') - (b[l] - 'a');
                        } else {
                            diff += abs((j + (b[l] - 'a')) - (strings[i][l] - 'a'));
                        }
                    }

                    if (k + diff <= m) {
                        new_ways[k + diff] += ways[j];
                        new_ways[k + diff] %= MOD;
                    }
                }
            }

            ways = new_ways;
        }

        cout << ways[m] << endl;
    }

    return 0;
}