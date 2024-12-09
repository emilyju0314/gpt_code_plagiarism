#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string s;
    int q;
    cin >> s >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        string x;
        cin >> l >> r >> x;

        set<string> substrings;
        for (int start = l - 1; start < r; start++) {
            for (int end = start; end < r; end++) {
                string substring = s.substr(start, end - start + 1);
                substrings.insert(substring);
            }
        }

        auto it = substrings.upper_bound(x);
        if (it == substrings.end()) {
            cout << "-1" << endl;
        } else {
            cout << *it << endl;
        }
    }

    return 0;
}