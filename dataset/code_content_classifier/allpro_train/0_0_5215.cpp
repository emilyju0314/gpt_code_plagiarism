#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int moves = 0;
        int sum = 1;
        while (sum < n) {
            int x = ceil((double)n / sum) - 1;
            sum += (x * (x + 1)) / 2;
            moves++;
        }

        cout << moves << endl;
    }

    return 0;
}