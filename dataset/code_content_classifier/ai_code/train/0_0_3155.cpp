#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n;
    cin >> n;

    vector<pair<char, string>> substitutions;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        string arrow, bi_ci;
        cin >> a >> arrow >> b >> bi_ci;
        substitutions.push_back(make_pair(a, b + bi_ci));
    }

    int m = s1.size();
    int l = s2.size();
    for (int i = 0; i < m; i++) {
        if (m - i < l) {
            continue;
        }

        bool match = true;
        for (int j = 0; j < l; j++) {
            if (s1[i + j] != s2[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            int diff = m - l;
            for (int j = 0; j < l; j++) {
                for (auto sub : substitutions) {
                    if (s2[j] == sub.first) {
                        diff++;
                        l += sub.second.size() - 1;
                        s2 = s2.substr(0, j) + sub.second + s2.substr(j + 1);
                        break;
                    }
                }
            }

            cout << diff << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}