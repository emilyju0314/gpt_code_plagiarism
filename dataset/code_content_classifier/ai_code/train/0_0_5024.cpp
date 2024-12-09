#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }

    sort(count.begin(), count.end(), greater<int>());

    string t = "";
    for (int i = 0; i < 26; i++) {
        t += string(count[i], 'a' + i);
    }

    cout << t << endl;

    return 0;
}