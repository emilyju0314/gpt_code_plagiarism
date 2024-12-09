#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.length();

    vector<int> diff;
    vector<pair<int, int>> segments;

    int start = -1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (start == -1) {
                start = i;
            }
        }
        else {
            if (start != -1) {
                diff.push_back(i - start);
                segments.push_back({start + 1, i});
                start = -1;
            }
        }
    }

    if (start != -1) {
        diff.push_back(n - start);
        segments.push_back({start + 1, n});
    }

    if (diff.size() % 2 != 0) {
        cout << -1 << endl;
    } else {
        cout << diff.size() / 2 << endl;
        for (int i = 0; i < diff.size(); i += 2) {
            cout << segments[i].first << " " << segments[i].second << endl;
            cout << segments[i + 1].first << " " << segments[i + 1].second << endl;
        }
    }

    return 0;
}