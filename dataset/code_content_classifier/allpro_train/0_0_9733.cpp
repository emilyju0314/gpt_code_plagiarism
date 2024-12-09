#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a_success = 0, a_total = 0;
    int b_success = 0, b_total = 0;

    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        
        if (t == 1) {
            a_success += x;
            a_total += 10;
        } else {
            b_success += x;
            b_total += 10;
        }
    }

    if (a_success * 2 >= a_total) {
        cout << "LIVE" << endl;
    } else {
        cout << "DEAD" << endl;
    }

    if (b_success * 2 >= b_total) {
        cout << "LIVE" << endl;
    } else {
        cout << "DEAD" << endl;
    }

    return 0;
}