#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int r(string& s, set<char>& c) {
    int count = 0;
    int n = s.length();
    vector<int> maxLen(n);

    for (int i = 0; i < n; i++) {
        int maxLength = 0;
        for (int j = i; j < n; j++) {
            if (c.count(s[j]) > 0) {
                maxLength++;
            } else {
                break;
            }
        }
        maxLen[i] = maxLength;
    }

    for (int i = 0; i < n; i++) {
        if (maxLen[i] > 0) {
            bool isMaximal = true;
            for (int j = i-1; j >= 0; j--) {
                if (maxLen[j] > maxLen[i]) {
                    isMaximal = false;
                    break;
                }
            }
            for (int j = i+1; j < n; j++) {
                if (maxLen[j] > maxLen[i]) {
                    isMaximal = false;
                    break;
                }
            }
            if (isMaximal) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;

    int m;
    cin >> m;
    
    vector<set<char>> sets;

    for (int i = 0; i < m; i++) {
        string c;
        cin >> c;
        set<char> charSet(c.begin(), c.end());
        sets.push_back(charSet);
    }

    for (set<char>& set : sets) {
        cout << r(s, set) << endl;
    }

    return 0;
}