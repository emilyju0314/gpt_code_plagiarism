#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool checkPrefixFree(const vector<string>& S) {
    unordered_set<string> prefixes;
    for (const string& s : S) {
        for (int i = 1; i < s.length(); i++) {
            if (prefixes.count(s.substr(0, i)) > 0) {
                return false;
            }
        }
        prefixes.insert(s);
    }
    return true;
}

int main() {
    int N, L;
    cin >> N >> L;

    vector<string> S;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }

    if (checkPrefixFree(S)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}