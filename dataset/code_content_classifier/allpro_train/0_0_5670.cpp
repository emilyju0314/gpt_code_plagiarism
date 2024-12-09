#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool hasOneDifference(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return false;
    }

    int diffCount = 0;
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] != s2[i]) {
            diffCount++;
        }
        if(diffCount > 1) {
            return false;
        }
    }

    return diffCount == 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> memories(n);
    for(int i = 0; i < n; i++) {
        cin >> memories[i];
    }

    for(int i = 0; i < m; i++) {
        string query;
        cin >> query;

        bool found = false;
        for(string memory : memories) {
            if(hasOneDifference(query, memory)) {
                found = true;
                break;
            }
        }

        if(found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}