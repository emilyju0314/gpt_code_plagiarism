#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    long long res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

long long choose(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

string solve(int n, int k, long long x, string s) {
    string res = "";
    int count_a = 0;
    vector<int> asterisk_positions;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            count_a++;
        } else {
            asterisk_positions.push_back(i);
        }
    }

    for(int i = 1; i <= asterisk_positions.size(); i++) {
        long long combinations = choose(asterisk_positions.size(), i);
        if(x <= combinations) {
            for(int j = 0; j < i; j++) {
                int idx = asterisk_positions[j];
                int b_count = min((long long) k, x);
                x -= b_count;
                for(int l = 0; l < b_count; l++) {
                    res += 'b';
                }
                res += 'a';
            }
            for(int j = 0; j < asterisk_positions.size() - i; j++) {
                int idx = asterisk_positions[j + i];
                res += 'a';
            }
            break;
        } else {
            x -= combinations;
        }
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;

        string s;
        cin >> s;

        string result = solve(n, k, x, s);
        cout << result << endl;
    }

    return 0;
}