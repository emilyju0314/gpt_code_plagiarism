#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    if (s.size() < k) {
        cout << "impossible" << endl;
        return 0;
    }

    int changes = max(0, k - (int)s.size());
    int distinct = 0;
    int count[26] = {0};

    for (char c : s) {
        count[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            distinct++;
        }
    }

    if (distinct >= k) {
        cout << changes << endl;
    } else {
        cout << k - distinct << endl;
    }

    return 0;
}