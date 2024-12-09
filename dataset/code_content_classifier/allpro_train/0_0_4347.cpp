#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int a = min(n / k, 1); // minimum number of candies each kid can have
        int b = min(n / k, 1) * k; // maximum number of candies one kid can have

        int remaining_candies = n - b;
        int extra_kids = min(remaining_candies, k/2);

        cout << b + extra_kids << endl;
    }

    return 0;
}