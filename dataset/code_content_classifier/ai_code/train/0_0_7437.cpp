#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

vector<long long> evaluate(vector<vector<vector<long long>>>& dp, string& s, int start, int end) {
    if (dp[start][end].size() != 0) {
        return dp[start][end];
    }

    vector<long long> res;
    if (start == end) {
        if (is_digit(s[start])) {
            res.push_back(s[start] - '0');
        }
    } else {
        for (int i = start + 1; i < end; i += 2) {
            vector<long long> left = evaluate(dp, s, start, i - 1);
            vector<long long> right = evaluate(dp, s, i + 1, end);
            for (long long l : left) {
                for (long long r : right) {
                    if (s[i] == '+') {
                        res.push_back(l + r);
                    } else if (s[i] == '*') {
                        res.push_back(l * r);
                    }
                }
            }
        }
    }

    return dp[start][end] = res;
}

int count_substrings(int target, string& s) {
    int n = s.size();
    vector<vector<vector<long long>> dp(n, vector<vector<long long>>(n, vector<long long>()));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<long long> values = evaluate(dp, s, i, j);
            for (long long value : values) {
                if (value == target) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    int target;
    string s;

    while (true) {
        cin >> target;
        if (target == 0) {
            break;
        }

        cin >> s;
        cout << count_substrings(target, s) << endl;
    }

    return 0;
}