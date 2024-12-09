#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

const int MOD = 998244353;

int f(const vector<string>& strings, const unordered_set<char>& subseq) {
    int res = 0;
    for (const string& s : strings) {
        bool found = false;
        for (char c : s) {
            if (subseq.count(c)) {
                found = true;
                break;
            }
        }
        if (found) {
            res++;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    unordered_set<char> charset;
    for (const string& s : strings) {
        for (char c : s) {
            charset.insert(c);
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        unordered_set<char> subseq;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (char c : strings[i]) {
                    subseq.insert(c);
                }
            }
        }

        ans ^= f(strings, subseq) * subseq.size();
    }

    cout << ans << endl;

    return 0;
}