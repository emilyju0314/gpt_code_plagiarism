#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSubstring(string s, string sub) {
    return s.find(sub) != string::npos;
}

int main() {
    int n;
    cin >> n;

    vector<string> titles(n);
    string allTitles = "";

    for (int i = 0; i < n; i++) {
        cin >> titles[i];
        allTitles += titles[i];
    }

    sort(allTitles.begin(), allTitles.end());

    string ans = "";

    for (char c = 'a'; c <= 'z'; c++) {
        string temp = ans + c;

        if (!isSubstring(allTitles, temp)) {
            ans += c;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}