#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> cnt(3);
    int mod = 0;
    int result = 0;

    for (char c : s) {
        int digit = c - '0';
        mod = (mod + digit) % 3;
        cnt[digit % 3]++;
    }

    if (mod == 0) {
        cout << 0 << endl;
    } else if (mod == 1) {
        if (cnt[1] >= 1 && s.size() > 1) {
            cout << 1 << endl;
        } else if (cnt[2] >= 2 && s.size() > 2){
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if (cnt[2] >= 1 && s.size() > 1) {
            cout << 1 << endl;
        } else if (cnt[1] >= 2 && s.size() > 2) {
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}