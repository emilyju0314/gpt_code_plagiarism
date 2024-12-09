#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool checkConstraints(string& s, vector<pair<char, pair<int, int>>>& constraints, int L, int R) {
    int satisfiedConstraints = 0;
    for (auto& constraint : constraints) {
        int count = 0;
        for (char c : s) {
            if (c == constraint.first) {
                count++;
            }
        }
        if (count >= constraint.second.first && count <= constraint.second.second) {
            satisfiedConstraints++;
        }
    }
    return satisfiedConstraints >= L && satisfiedConstraints <= R;
}

int main() {
    string s;
    int k, L, R;
    cin >> s >> k >> L >> R;

    vector<pair<char, pair<int, int>>> constraints;
    for (int i = 0; i < k; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        constraints.push_back(make_pair(c, make_pair(l, r));
    }

    int substringsCount = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j <= s.size() - i; j++) {
            string substr = s.substr(i, j);
            if (checkConstraints(substr, constraints, L, R)) {
                substringsCount++;
            }
        }
    }

    cout << substringsCount << endl;

    return 0;
}