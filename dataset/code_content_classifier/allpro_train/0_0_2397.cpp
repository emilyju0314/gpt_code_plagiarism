#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int min_good_apartments, max_good_apartments;

    if (k == 0 || k == n) {
        min_good_apartments = 0;
    } else {
        min_good_apartments = 1;
    }

    if (k * 2 <= n) {
        max_good_apartments = k * 2;
    } else {
        max_good_apartments = n - k;
    }

    cout << min_good_apartments << " " << max_good_apartments << endl;

    return 0;
}