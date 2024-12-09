#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    string t(n, '0');

    int zeros = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeros++;
    }

    int ones = n - zeros;

    // If the number of zeros in s is greater than half of the length of s,
    // then we can make t have all zeros except for one where there is 1 in s
    if (zeros > n / 2) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                t[i] = '1';
                break;
            }
        }
    } 
    // Otherwise, we can make t have all zeros except for one in each non-decreasing subsequence of 1s
    else {
        int cnt_ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt_ones++;
                t[i] = '1';
            }
            else {
                if (cnt_ones > 0) {
                    t[i-cnt_ones] = '1';
                    cnt_ones = 0;
                }
            }
        }
    }

    cout << t << endl;

    return 0;
}