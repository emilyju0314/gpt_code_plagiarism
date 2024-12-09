#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, char>> t(n);
    for (int i = 0; i < n; i++) {
        char c;
        int l;
        cin >> l >> c;
        t[i] = make_pair(l, c);
    }

    vector<pair<int, char>> s(m);
    for (int i = 0; i < m; i++) {
        char c;
        int l;
        cin >> l >> c;
        s[i] = make_pair(l, c);
    }

    int occurrences = 0;
    for (int i = 0; i <= n - m; i++) {
        bool found = true;
        for (int j = 0; j < m; j++) {
            if (t[i + j].first != s[j].first || t[i + j].second != s[j].second) {
                found = false;
                break;
            }
        }
        if (found) {
            occurrences++;
        }
    }

    cout << occurrences << endl;

    return 0;
}