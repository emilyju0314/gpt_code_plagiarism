#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool canMakeStringsEqual(vector<string> strings) {
    string target = strings[0];
    sort(target.begin(), target.end());

    for (int i = 1; i < strings.size(); i++) {
        string current = strings[i];
        sort(current.begin(), current.end());
        if (target != current) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<string> strings(n);
        for (int j = 0; j < n; j++) {
            cin >> strings[j];
        }

        if (canMakeStringsEqual(strings)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}