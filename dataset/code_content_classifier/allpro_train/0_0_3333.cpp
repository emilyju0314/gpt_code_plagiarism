#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> piles(n);
    int xor_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        xor_sum ^= piles[i];
    }

    if (xor_sum == 0) {
        cout << "Nicky" << endl;
    } else {
        if (n % 2 == 0) {
            cout << "Kevin" << endl;
        } else {
            cout << "Nicky" << endl;
        }
    }

    return 0;
}