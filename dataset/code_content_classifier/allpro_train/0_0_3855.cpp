#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string vowels, s;
    int n, m;
    cin >> vowels;
    cin >> n >> m;

    vector<pair<int, char>> rules[n+1];
    for (int i = 0; i < m; i++) {
        int pos1, pos2;
        char t1, t2;
        cin >> pos1 >> t1 >> pos2 >> t2;
        rules[pos1].push_back(make_pair(pos2, t2));
        rules[pos2].push_back(make_pair(pos1, t1));
    }

    cin >> s;

    vector<char> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = s[i];
    }

    for (int i = n-1; i >= 0; i--) {
        bool found = false;
        for (char c = s[i]+1; c <= 'z'; c++) {
            result[i] = c;
            bool valid = true;
            for (int j = 0; j < rules[i+1].size(); j++) {
                int nextPos = rules[i+1][j].first;
                char type = rules[i+1][j].second;
                if ((type == 'V' && vowels.find(result[i]) == string::npos) || (type == 'C' && vowels.find(result[i]) != string::npos)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}