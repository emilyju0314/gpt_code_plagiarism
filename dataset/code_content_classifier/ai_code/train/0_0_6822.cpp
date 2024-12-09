#include <iostream>

using namespace std;

int main() {
    long long x;
    cin >> x;

    // Calculate the remaining points after getting the maximum top face value of 6
    long long remaining = x % 11;

    // Calculate the minimum number of operations needed to reach or exceed x points
    long long operations = x / 11 * 2;
    if(remaining > 0) {
        if(remaining <= 6) {
            operations += 1;
        } else {
            operations += 2;
        }
    }

    cout << operations << endl;

    return 0;
}