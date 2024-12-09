#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool matchesPattern(string goodLetters, string pattern, string query) {
    if(pattern.length() > query.length()) {
        return false;
    }

    for (int i = 0; i < pattern.length(); i++) {
        if(pattern[i] == '?') {
            if(goodLetters.find(query[i]) == string::npos) {
                return false;
            }
        }
    }

    if(pattern.length() < query.length() && pattern.find('*') == string::npos) {
        return false;
    }

    int starIndex = pattern.find('*');
    if(starIndex == string::npos) {
        return pattern == query;
    }

    string prefix = pattern.substr(0, starIndex);
    string suffix = pattern.substr(starIndex + 1);

    if(query.length() < prefix.length() + suffix.length()) {
        return false;
    }

    if(query.substr(0, prefix.length()) != prefix) {
        return false;
    }

    if(query.substr(query.length() - suffix.length()) != suffix) {
        return false;
    }

    for(int i = prefix.length(); i < query.length() - suffix.length(); i++) {
        if(goodLetters.find(query[i]) != string::npos) {
            return false;
        }
    }

    return true;
}

int main() {
    string goodLetters, pattern;
    int n;
    cin >> goodLetters >> pattern >> n;

    vector<string> queries(n);
    for(int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    for(int i = 0; i < n; i++) {
        if(matchesPattern(goodLetters, pattern, queries[i])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}