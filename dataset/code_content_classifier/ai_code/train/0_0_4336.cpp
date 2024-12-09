#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ways = 0;
    
    if (n >= 11 && n <= 21) {
        ways = 4; // Four twos of different suits can earn the required sum of points
    }
    
    if (n >= 10) {
        ways += 4; // All tens, jacks, queens and kings can earn the required sum of points
        ways += 4; // Four twos of different suits can also earn the required sum of points
    }
    
    if (n == 21) {
        ways -= 1; // The queen of spades (already in use) should be excluded
    }
    
    cout << ways << endl;
    
    return 0;
}