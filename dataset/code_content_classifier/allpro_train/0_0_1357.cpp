#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool containsBoringString(string s, vector<string> boringStrings) {
    for (string boringStr : boringStrings) {
        if (s.find(boringStr) != string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    int n;
    cin >> s >> n;

    vector<string> boringStrings(n);
    for (int i = 0; i < n; i++) {
        cin >> boringStrings[i];
    }

    int longestLength = 0;
    int startPos = 0;

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            string sub = s.substr(i, j-i+1);
            if (!containsBoringString(sub, boringStrings) && sub.length() > longestLength) {
                longestLength = sub.length();
                startPos = i;
            }
        }
    }

    cout << longestLength << " " << startPos << endl;

    return 0;
}