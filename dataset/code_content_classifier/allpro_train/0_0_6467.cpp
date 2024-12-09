#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int countDistinctSubstrings(string s) {
    int n = s.size();
    unordered_set<string> substrings;

    for (int i = 0; i < n; i++) {
        string sub = "";
        for (int j = i; j < n; j++) {
            sub += s[j];
            substrings.insert(sub);
        }
    }

    return substrings.size();
}

int main() {
    string s;
    cin >> s;

    cout << countDistinctSubstrings(s) << endl;

    return 0;
}