#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cout << n + (n-1) << endl; // Maximum possible time for the robot to finish

        cout << "1 "; // Initial permutation
        for(int i = 2; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;

        cout << n << endl; // Number of operations

        for(int i = n; i >= 2; i--) {
            cout << i << " 1" << endl; // Indices of positions that the robot will swap
        }
    }

    return 0;
}