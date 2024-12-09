#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    string target = "heidi";
    int n = s.length();
    int m = target.length();
    int j = 0;

    for (int i = 0; i < n && j < m; i++) {
        if (s[i] == target[j]) {
            j++;
        }
    }

    if (j == m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}