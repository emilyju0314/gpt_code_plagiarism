#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long ways = 0;
    
    // For each make of car, calculate the number of ways to fill the parking lot
    for(int i = 0; i < 4; i++) {
        // Calculate the number of ways with n successive cars of the same make
        long long curWays = 1;
        for(int j = 0; j < n; j++) {
            curWays *= 2 * n - 1 - j; // Combination formula nCr = n! / ((n-r)! * r!)
            curWays /= j + 1;
        }
        
        ways += curWays;
    }

    // Calculate the total number of ways to fill the parking lot
    ways *= 4;
    
    cout << ways << endl;

    return 0;
}