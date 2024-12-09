#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    unordered_map<string, vector<int>> indices;
    for (int i = 0; i < s.length(); i++) {
        string sub = "";
        for (int j = i; j < s.length(); j++) {
            sub += s[j];
            indices[sub].push_back(i);
        }
    }

    for (int i = 0; i < q; i++) {
        string ai, bi;
        cin >> ai >> bi;

        if (indices.count(ai) == 0 || indices.count(bi) == 0) {
            cout << -1 << endl;
        } else {
            int min_len = s.length();
            for (int idx_ai : indices[ai]) {
                for (int idx_bi : indices[bi]) {
                    int start = min(idx_ai, idx_bi);
                    int end = max(idx_ai, idx_bi) + ai.length();
                    min_len = min(min_len, end - start);
                }
            }
            if (min_len == s.length()) {
                cout << -1 << endl;
            } else {
                cout << min_len << endl;
            }
        }
    }

    return 0;
}