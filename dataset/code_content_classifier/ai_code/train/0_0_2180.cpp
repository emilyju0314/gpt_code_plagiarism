#include <iostream>
#include <string>
using namespace std;

int f(string t) {
    int res = 0;
    for (int i = 0; i < t.length(); i++) {
        res = (res << 1) + (t[i] - '0');
    }
    return res;
}

int countGoodSubstrings(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            string sub = s.substr(i, j-i+1);
            if (j - i + 1 == f(sub)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        
        cout << countGoodSubstrings(s) << endl;
    }

    return 0;
}