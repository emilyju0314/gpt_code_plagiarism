#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases

    while (t--) {
        int n, k;
        cin >> n >> k; // length of the string and required period

        string s;
        cin >> s; // input string s

        int min_moves = 0;
        int curr_period = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                curr_period = 0;
                for (int j = i - k; j < i; j++) {
                    if (j >= 0 && s[j] == '1') {
                        min_moves++; // incrementing moves to fix the period
                        s[j] = '0'; // changing state of the lamp
                    }
                }
            } else {
                curr_period++;
                if (curr_period == k) {
                    s[i] = '1'; // changing state of the lamp
                    curr_period = 0;
                    min_moves++; // incrementing moves to fix the period
                }
            }
        }

        cout << min_moves << endl; // outputting minimum number of moves needed
    }

    return 0;
}