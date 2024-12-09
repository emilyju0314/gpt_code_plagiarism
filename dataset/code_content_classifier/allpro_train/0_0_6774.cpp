#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int p = -1;

    cout << "? 1" << endl;
    int cards_at_1;
    cin >> cards_at_1;

    if (cards_at_1 == k) {
        cout << "? 2" << endl;
        int cards_at_2;
        cin >> cards_at_2;

        if (cards_at_2 != k) {
            p = 1;
        }
    } else {
        p = 2;
    }

    for (int i = 3; i <= n; i++) {
        cout << "? " << i << endl;
        int cards_at_i;
        cin >> cards_at_i;

        if (p == -1) {
            if (cards_at_i == k) {
                p = i;
            }
        }
    }

    cout << "! " << p << endl;

    return 0;
}