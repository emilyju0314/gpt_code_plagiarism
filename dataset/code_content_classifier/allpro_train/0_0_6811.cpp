#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<vector<int>> subsequences;
    vector<int> subsequence;

    int current = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0' != current) {
            if (!subsequence.empty()) {
                subsequences.push_back(subsequence);
                subsequence.clear();
            }
            current = s[i] - '0';
        }
        subsequence.push_back(i + 1);
    }
    if (!subsequence.empty()) {
        subsequences.push_back(subsequence);
    }

    if (subsequences.size() < 3 || s[0] == s[s.size() - 1] || subsequences[0].size() < 2 || subsequences[subsequences.size() - 1].size() < 2) {
        cout << "-1" << endl;
    } else {
        cout << subsequences.size() << endl;
        for (auto sub : subsequences) {
            cout << sub.size() << " ";
            for (int day : sub) {
                cout << day << " ";
            }
            cout << endl;
        }
    }

    return 0;
}