#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool lex_compare(const string& s1, const string& s2) {
    return s1 < s2;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> packages(n);
        for(int i = 0; i < n; i++) {
            cin >> packages[i].first >> packages[i].second;
        }

        sort(packages.begin(), packages.end());

        string path = "";
        bool possible = true;
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            int dx = packages[i].first - x;
            int dy = packages[i].second - y;

            if(dx < 0 || dy < 0) {
                possible = false;
                break;
            }

            path += string(dx, 'R') + string(dy, 'U');
            x = packages[i].first;
            y = packages[i].second;
        }

        if(possible) {
            cout << "YES" << endl;
            cout << path << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}