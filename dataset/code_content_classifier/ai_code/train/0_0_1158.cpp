#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) 
        return false;
    if (n <= 3) 
        return true;
    if (n % 2 == 0 || n % 3 == 0) 
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int smatch(string s, int d, vector<int>& digits) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '?' && digits[i] != s[i]-'0')
            return 0;
    }
    int num = 0;
    for (int i = 0; i < digits.size(); ++i) {
        num *= d;
        num += digits[i];
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        int d, c;
        string s;
        cin >> d >> s >> c;
        bool found = false;
        for (int num = 0; num < pow(d, s.size()); ++num) {
            vector<int> digits;
            int tmp = num;
            for (int i = 0; i < s.size(); ++i) {
                digits.push_back(tmp % d);
                tmp /= d;
            }
            reverse(digits.begin(), digits.end());

            int matched = smatch(s, d, digits);
            if (matched != 0) {
                int control = c;
                for (int i = 0; i < n; ++i) {
                    if (matched & (1<<i)) {
                        control += prices[i];
                    }
                }
                for (int k = 2; k <= 100; ++k) {
                    if (control % k == 0 && is_prime(k)) {
                        cout << k << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << -1 << endl;
                }
                break;
            }
        }
    }

    return 0;
}