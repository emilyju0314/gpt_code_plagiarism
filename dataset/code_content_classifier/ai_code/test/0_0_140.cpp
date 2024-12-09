#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int count = 0;

        // Count squares
        count += sqrt(n);

        // Count cubes
        count += cbrt(n);

        // Subtract the common numbers counted twice
        count -= sqrt(cbrt(n));

        cout << count << endl;
    }

    return 0;
}