#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n, k;
        cin >> n >> k;

        vector<int> piles(n);
        for(int i = 0; i < n; i++) {
            cin >> piles[i];
        }

        int max_casts = 0;
        while(true) {
            int max_pile_idx = -1;
            int max_pile_size = 0;

            // Find the pile with maximum candies
            for(int i = 0; i < n; i++) {
                if(piles[i] > max_pile_size) {
                    max_pile_idx = i;
                    max_pile_size = piles[i];
                }
            }

            // If there is no pile with more than k candies, break
            if(max_pile_size <= k) {
                break;
            }

            // Cast spell from max_pile_idx to other piles
            for(int i = 0; i < n; i++) {
                if(i != max_pile_idx) {
                    int diff = min(k - piles[i], piles[max_pile_idx]);
                    piles[i] += diff;
                    piles[max_pile_idx] -= diff;
                }
            }

            max_casts++;
        }

        cout << max_casts << endl;
    }

    return 0;
}