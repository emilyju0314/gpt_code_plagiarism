#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char, int> color;
    int count = 0;
    for (char c : s) {
        if (color.find(c) == color.end()) {
            color[c] = ++count;
        }
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = color[s[i]];
    }

    cout << count << endl;
    for (int c : res) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}