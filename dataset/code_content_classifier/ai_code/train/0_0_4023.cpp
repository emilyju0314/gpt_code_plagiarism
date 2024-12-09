#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int countSubstringWays(string s, string t) {
    long long count = 1;
    vector<int> positions;

    for (size_t i = 0; i + t.length() <= s.length(); i++) {
        if (s.substr(i, t.length()) == t) {
            positions.push_back(i);
        }
    }

    for (size_t i = 1; i < positions.size(); i++) {
        count = (count * (positions[i] - positions[i-1])) % MOD;
    }

    return count;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << countSubstringWays(s, t) << endl;

    return 0;
}