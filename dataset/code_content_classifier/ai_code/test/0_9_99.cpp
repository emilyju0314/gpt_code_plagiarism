#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long x, n;
        cin >> x >> n;

        // Calculate the final position after n jumps
        long long position = x;

        // Determine the direction of the jump based on the parity of the current position
        bool isEven = (position % 2 == 0);

        for(int i = 1; i <= n; i++) {
            if(isEven) {
                position -= i;
            } else {
                position += i;
            }

            isEven = !isEven;
        }

        cout << position << "\n";
    }

    return 0;
}