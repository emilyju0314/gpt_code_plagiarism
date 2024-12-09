#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, l, r;
    cin >> a >> b >> l >> r;

    vector<char> s;
    for (char c = 'a'; c <= 'a' + a - 1; c++) {
        s.push_back(c);
    }

    int min_diff_letters = 0;
    for (int i = l; i <= r; i++) {
        if (i % (a + b) <= a && i % (a + b) != 0) {
            min_diff_letters += min(a, r - i + 1);
        }
    }

    cout << min_diff_letters << endl;

    return 0;
}