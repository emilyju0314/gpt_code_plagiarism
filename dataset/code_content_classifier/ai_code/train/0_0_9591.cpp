#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool areIsomorphic(const string& s1, const string& s2) {
    if(s1.length() != s2.length()) {
        return false;
    }

    unordered_map<char, char> charMap;
    unordered_map<char, char> charMapReverse;

    for(int i = 0; i < s1.length(); i++) {
        char c1 = s1[i];
        char c2 = s2[i];

        if(charMap.find(c1) == charMap.end()) {
            charMap[c1] = c2;
        } else {
            if(charMap[c1] != c2) {
                return false;
            }
        }

        if(charMapReverse.find(c2) == charMapReverse.end()) {
            charMapReverse[c2] = c1;
        } else {
            if(charMapReverse[c2] != c1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    while(m--) {
        int x, y, len;
        cin >> x >> y >> len;

        string sub1 = s.substr(x - 1, len);
        string sub2 = s.substr(y - 1, len);

        if(areIsomorphic(sub1, sub2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}