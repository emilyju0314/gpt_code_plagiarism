#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string start, end;
        cin >> start >> end;

        int operations = 1;
        for (int i = 0; i < n; i++) {
            if (start[i] == '0' && end[i] == '1') {
                operations = 0;
                break;
            }

            if (start[i] == '?' && end[i] == '?') {
                operations = (2 * operations) % MOD;
            } else if (start[i] == '?' || end[i] == '?') {
                operations = (3 * operations) % MOD;
            }
        }

        cout << operations << endl;
    }

    return 0;
}