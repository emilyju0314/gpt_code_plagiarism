#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> sequence(n, 0);

    // First, find out the number of 1s at positions 1 and 2
    cout << "? 1 1" << endl;
    cout.flush();
    int ones_at_1 = 0;
    cin >> ones_at_1;

    cout << "? 2 2" << endl;
    cout.flush();
    int ones_at_2 = 0;
    cin >> ones_at_2;

    // Calculate the number of 1s at position 1 and 2
    int diff = ones_at_1 - ones_at_2;
    if (abs(diff) == 2) {
        sequence[0] = 1;
        sequence[1] = 1;
    } else if (diff == 0) {
        sequence[0] = 1;
    }

    // Fill the rest of the sequence
    for (int i = 2; i < n; i++) {
        cout << "? 1 " << i+1 << endl;
        cout.flush();
        int ones_so_far = 0;
        cin >> ones_so_far;

        int expected_ones = i - ones_so_far;
        if (expected_ones == sequence[i-1]) {
            sequence[i] = 0;
        } else {
            sequence[i] = 1;
        }
    }

    // Print the final sequence
    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << sequence[i];
    }
    cout << endl;
    cout.flush();

    return 0;
}