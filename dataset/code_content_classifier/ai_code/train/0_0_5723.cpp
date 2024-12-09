#include <iostream>

using namespace std;

int main() {
    int k, l;
    cin >> k >> l;

    int count = 0;
    while (l % k == 0) {
        l /= k;
        count++;
    }

    if (l == 1) {
        cout << "YES" << endl;
        cout << count << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}