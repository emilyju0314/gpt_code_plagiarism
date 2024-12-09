#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> compartments(n);
    for (int i = 0; i < n; i++) {
        cin >> compartments[i];
    }

    int total_swaps = 0;
    int num_ones = 0, num_twos = 0;
    for (int i = 0; i < n; i++) {
        if (compartments[i] == 1) {
            num_ones++;
            if (num_ones % 2 == 0) {
                total_swaps += 2;
            }
        } else if (compartments[i] == 2) {
            num_twos++;
            if (num_twos % 2 == 0) {
                total_swaps += 2;
            }
        } else if (compartments[i] == 3) {
            // No need to swap
        } else if (compartments[i] == 4) {
            // No need to swap
        }
    }

    if (num_ones % 2 == 1 && num_twos % 2 == 1) {
        total_swaps += 2;
    } else if (num_ones % 2 == 1 || num_twos % 2 == 1) {
        total_swaps++;
    }

    cout << total_swaps << endl;

    return 0;
}