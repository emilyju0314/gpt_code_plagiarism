#include <iostream>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a1, m1, a2, m2, a3, m3;
    
    while (cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3) {
        if (a1 == 0 && m1 == 0 && a2 == 0 && m2 == 0 && a3 == 0 && m3 == 0) break;
        
        // Calculate the least common multiple of the moduli
        int lcm = m1 * (m2 / gcd(m1, m2)) * (m3 / gcd(m1, m3));
        
        // Calculate the remainder of lcm when divided by a1, a2, a3 respectively
        int r1 = lcm % a1;
        int r2 = lcm % a2;
        int r3 = lcm % a3;
        
        // Check if the remainders are equal to 1
        if (r1 == 1 && r2 == 1 && r3 == 1) {
            cout << lcm << endl;
        } else {
            // If not, calculate the next multiple of lcm that results in remainders 1
            int result = max({a1 - r1, a2 - r2, a3 - r3});
            cout << lcm + result << endl;
        }
    }
    
    return 0;
}