#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0) {
            break;
        }

        vector<int> cards(n + 1, 0);  // Initialize with 0
        for (int i = 0; i < k; i++) {
            int num;
            cin >> num;
            cards[num] = 1;  // Mark the given card numbers
        }

        int max_length = 0;
        int current_length = 0;
        for (int i = 1; i <= n; i++) {
            if (cards[i] == 1) {
                current_length++;
            } else {
                max_length = max(max_length, current_length);
                current_length = 0;
            }
        }
        
        max_length = max(max_length, current_length);  // Check one more time after the loop ends
        cout << max_length << endl;
    }

    return 0;
}