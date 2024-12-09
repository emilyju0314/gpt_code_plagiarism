#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isSuperLucky(string num) {
    int count4 = count(num.begin(), num.end(), '4');
    int count7 = count(num.begin(), num.end(), '7');
    return count4 == count7 && count4 > 0;
}

int main() {
    string n;
    cin >> n;

    while (!isSuperLucky(n)) {
        int idx = n.size() - 1;
        while (idx >= 0 && n[idx] == '7') {
            n[idx] = '4';
            idx--;
        }

        if (idx >= 0) {
            n[idx] = '7';
        } else {
            n = '4' + n;
        }
    }

    cout << n << endl;

    return 0;
}