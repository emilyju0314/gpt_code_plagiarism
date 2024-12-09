#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long x, n;
        cin >> x >> n;

        long long d = 1 + 8*n; // discriminant of the quadratic equation to find i
        long long i = (-1 + sqrt(d)) / 2; // find the i corresponding to n jumps

        long long finalPosition;
        if(i % 2 == 0) { // if i is even, jump to the left
            finalPosition = x - (n - i*(i+1)/2); // calculate final position
        } else { // if i is odd, jump to the right
            finalPosition = x + (n - i*(i+1)/2); // calculate final position
        }

        cout << finalPosition << endl;
    }

    return 0;
}