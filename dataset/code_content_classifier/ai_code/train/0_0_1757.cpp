#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    long long ans = 1;
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            int idx = -1;
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (names[j][i] == c) {
                    if (idx == -1) {
                        idx = j;
                    } else {
                        found = true;
                        break;
                    }
                }
            }
            if (!found && idx != -1) {
                count++;
            }
        }
        ans = (ans * count) % MOD;
    }

    cout << ans << endl;

    return 0;
}