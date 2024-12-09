#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, r_b, c_b, r_d, c_d;
        cin >> n >> m >> r_b >> c_b >> r_d >> c_d;

        int dr = abs(r_d - r_b);
        int dc = abs(c_d - c_b);
        
        // Check if the robot is already in the same row or column as the dirty cell
        if (r_b == r_d || c_b == c_d) {
            cout << max(dr, dc) << endl;
        } else {
            // Move the robot towards the dirty cell and add 2 seconds for each cleaning
            cout << dr + dc + 2 << endl;
        }
    }

    return 0;
}