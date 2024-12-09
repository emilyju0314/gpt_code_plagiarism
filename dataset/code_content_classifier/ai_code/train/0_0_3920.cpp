#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> diff_count(k, 0);
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                diff_count[i] += s[j] - '0';
            }
        }

        bool possible = false;
        bool all_zeros = true;
        bool all_ones = true;
        for (int i = 0; i < k; i++) {
            if (diff_count[i] == 0) {
                all_ones = false;
            } else if (diff_count[i] == n / k) {
                all_zeros = false;
            } else {
                possible = true;
            }
        }

        if (all_zeros || all_ones) {
            cout << "YES" << endl;
            for (int i = 0; i < k; i++) {
                cout << (all_zeros ? "0" : "1");
            }
            cout << endl;
        } else if (possible) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < k; i++) {
                cout << "0";
            }
            cout << endl;
        }
    }

    return 0;
}