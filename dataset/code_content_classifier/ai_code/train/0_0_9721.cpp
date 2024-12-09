#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minOperations(string s, string t) {
    if(s == t) {
        return 0;
    }

    int n = s.size();
    vector<int> count(26, 0);

    for(int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++) {
        if(count[i] != 0) {
            return -1;
        }
    }

    for(int len = 1; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            string tmp = s.substr(i, len) + s.substr(0, i) + s.substr(i + len);
            if(tmp == t) {
                return 1;
            }
        }
    }

    return 2;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        cout << minOperations(s, t) << endl;
    }

    return 0;
}