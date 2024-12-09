#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int minOperations(string s, string t) {
    unordered_map<char, vector<int>> indexMap;

    for (int i = 0; i < s.length(); i++) {
        indexMap[s[i]].push_back(i);
    }

    int prevIndex = -1;
    int operations = 1;

    for (char c : t) {
        if (indexMap.find(c) == indexMap.end()) {
            return -1;
        }

        vector<int>& indices = indexMap[c];
        auto it = upper_bound(indices.begin(), indices.end(), prevIndex);

        if (it == indices.end()) {
            operations++;
            prevIndex = -1;
            it = upper_bound(indices.begin(), indices.end(), prevIndex);
        }

        prevIndex = *it;
    }

    return operations;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s, t;
        cin >> s >> t;

        int result = minOperations(s, t);
        cout << result << endl;
    }

    return 0;
}