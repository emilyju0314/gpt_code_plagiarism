#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<pair<char, int>> operations;

    for (int i = 1; i <= n / 2; i++) {
        if (s[i - 1] != s[n - i]) {
            if (s[i - 1] == s[n - i - 1]) {
                operations.push_back({'R', n - i});
                s.insert(s.begin() + n - 1, s[i - 1]);
            } else if (s[i] == s[n - i]) {
                operations.push_back({'L', i + 1});
                s.insert(s.begin() + i, s[n - i]);
            } else {
                operations.push_back({'L', 2});
                s.insert(s.begin() + 1, s[i - 1]);
            }
        }
    }

    cout << operations.size() << endl;
    for (auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}