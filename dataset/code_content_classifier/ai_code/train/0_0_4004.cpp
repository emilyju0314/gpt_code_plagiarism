#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> piles(n);
        int maxPile = 0;
        int totalStones = 0;

        for(int j = 0; j < n; j++) {
            cin >> piles[j];
            totalStones += piles[j];
            maxPile = max(maxPile, piles[j]);
        }

        if (maxPile * 2 > totalStones || totalStones % 2 != 0) {
            cout << "T" << endl;
        } else {
            cout << "HL" << endl;
        }
    }

    return 0;
}