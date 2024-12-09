#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> possible_periods;

        for(int d = 1; d <= n; d++) {
            if(n % d == 0) {
                bool valid = true;
                for(int i = 0; i < d; i++) {
                    char ch = '?';
                    for(int j = i; j < n; j += d) {
                        if(s[j] != '?') {
                            if(ch == '?') {
                                ch = s[j];
                            }
                            else if(ch != s[j]) {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if(!valid) break;
                }
                if(valid) possible_periods.push_back(d);
            }
        }

        cout << possible_periods.size() << endl;
        for(int period : possible_periods) {
            cout << period << " ";
        }
        cout << endl;
    }

    return 0;
}