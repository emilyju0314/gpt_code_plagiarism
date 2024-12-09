#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int b1, q, l, m;
    cin >> b1 >> q >> l >> m;

    unordered_set<int> badIntegers;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        badIntegers.insert(num);
    }

    if (q == 0) {
        if (badIntegers.count(b1) == 0 && abs(b1) <= l) {
            cout << "inf" << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        if (badIntegers.count(b1) > 0) {
            cout << 0 << endl;
        } else {
            int count = 0;
            while (abs(b1) <= l) {
                count++;
                b1 *= q;
                if (q == 1 && badIntegers.count(b1) > 0) {
                    break;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}