#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, d;
        cin >> n >> d;

        vector<int> piles(n);
        for(int i = 0; i < n; i++) {
            cin >> piles[i];
        }

        int max_haybales = piles[0]; // Initialize with the number of haybales in pile 1

        for(int i = 1; i < n; i++) {
            int days_to_move = min(d, i * piles[i]);
            max_haybales += days_to_move / i;
            d -= days_to_move;
        }

        cout << max_haybales << endl;
    }

    return 0;
}