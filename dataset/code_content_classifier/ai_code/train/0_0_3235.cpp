#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, n, p, h;
        cin >> a >> n >> p >> h;

        if (a * n >= p || h >= p) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
} 

// The code reads the number of problem instances, t. Then, for each instance, it reads the values of a, n, p, and h. 
// It then checks if a*n is greater than or equal to p, or if h is greater than or equal to p. If either condition is true, 
// it outputs "NO", indicating that the Doodler cannot reach the highest platform. Otherwise, it outputs "YES".