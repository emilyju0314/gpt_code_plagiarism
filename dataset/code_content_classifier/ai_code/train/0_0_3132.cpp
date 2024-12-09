#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string s, vector<string>& strings) {
    for (string str : strings) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != s[i]) {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
    }
    return true;
}

string findString(vector<string>& strings) {
    int n = strings.size();
    int m = strings[0].length();

    for (char ch = 'a'; ch <= 'z'; ch++) {
        string s = strings[0];
        for (int i = 0; i < m; i++) {
            s[i] = ch;
            if (isValid(s, strings)) {
                return s;
            }
        }
    }

    return "-1";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> strings(n);
        for (int i = 0; i < n; i++) {
            cin >> strings[i];
        }

        string result = findString(strings);
        cout << result << endl;
    }

    return 0;
}