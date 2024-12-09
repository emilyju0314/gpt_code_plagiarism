#include <iostream>
using namespace std;

bool check(int x, int p) {
    if (x <= 1) return true;
    if (p == 0) return false;
    if (check(x/2, p-1)) return true;
    if (check(x-1, p-1)) return true;
    return false;
}

int main() {
    int l, r, p;
    cin >> l >> r >> p;

    int count = 0;
    for (int x = l; x <= r; x++) {
        if (check(x, p)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}