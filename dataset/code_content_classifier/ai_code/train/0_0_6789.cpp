#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countMatches(string s, int length) {
    int count = 0;
    for (int i = 0; i < s.size() - length; i++) {
        if (s.substr(i, length) == s.substr(s.size() - length, length)) {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;

    int totalMatches = 0;
    vector<pair<int, int>> matches;

    for (int i = 1; i <= s.size(); i++) {
        int matchCount = countMatches(s, i);
        if (matchCount > 0) {
            matches.push_back({i, matchCount});
            totalMatches += matchCount;
        }
    }

    cout << totalMatches << endl;
    for (int i = 0; i < matches.size(); i++) {
        cout << matches[i].first << " " << matches[i].second << endl;
    }

    return 0;
}