#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // To get the smallest value divisible by a
        int resa = b % a;
        int a1 = b - resa;

        // To get the smallest value divisible by b and c
        int resb = c % b;
        int b1 = c - resb;
        
        // Calculate the minimum number of operations
        int operations = abs(a - a1) + abs(b - b1) + abs(c - b1);

        cout << operations << endl;
        cout << a1 << " " << b1 << " " << c << endl;
    }

    return 0;
}