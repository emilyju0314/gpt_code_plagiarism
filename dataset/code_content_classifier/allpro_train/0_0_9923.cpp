#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int maxDigits = 1;
    while (n > 7 || m > 7) {
        n = (n + 6) / 7;
        m = (m + 6) / 7;
        maxDigits++;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            set<int> digits;
            int curi = i, curj = j;
            bool valid = true;
            while (curi > 0) {
                if (digits.count(curi % 7)) {
                    valid = false;
                    break;
                }
                digits.insert(curi % 7);
                curi /= 7;
            }
            while (curj > 0) {
                if (digits.count(curj % 7)) {
                    valid = false;
                    break;
                }
                digits.insert(curj % 7);
                curj /= 7;
            }
            if (valid) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}