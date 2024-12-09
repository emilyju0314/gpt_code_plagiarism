#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        xorSum ^= piles[i];
    }

    if (xorSum == 0) {
        cout << "Rublo" << endl;
    } else {
        cout << "Furlo" << endl;
    }

    return 0;
}