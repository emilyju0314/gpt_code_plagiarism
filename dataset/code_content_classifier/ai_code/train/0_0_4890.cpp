#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    string original_state, desired_state;
    cin >> original_state >> desired_state;

    int total_moves = 0;
    for (int i = 0; i < n; i++) {
        int digit_original = original_state[i] - '0';
        int digit_desired = desired_state[i] - '0';
        total_moves += min(abs(digit_original - digit_desired), 10 - abs(digit_original - digit_desired));
    }

    cout << total_moves << endl;

    return 0;
}