#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int totalStones = 0;
        int maxPile = 0;
        for(int i = 0; i < n; i++) {
            int stones;
            cin >> stones;
            totalStones += stones;
            maxPile = max(maxPile, stones);
        }

        if (maxPile <= totalStones / 2) {
            if (totalStones % 2 == 0) {
                cout << "HL" << endl;
            } else {
                cout << "T" << endl;
            }
        } else {
            cout << "T" << endl;
        }
    }

    return 0;
}