#include <iostream>
#include <string>

using namespace std;

bool isBeautiful(int num) {
    string s = to_string(num);
    for (char c : s) {
        if (c == '0') continue;
        if (num % (c - '0') != 0) return false;
    }
    return true;
}

int countBeautifulNumbers(int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        if (isBeautiful(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << countBeautifulNumbers(l, r) << endl;
    }

    return 0;
}