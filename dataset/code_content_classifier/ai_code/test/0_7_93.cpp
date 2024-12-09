#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long time = 0;
        long long computers = 1; // initialize with 1st computer

        // Calculate the minimum number of hours required
        while (computers < n) {
            computers += min(n - computers, k) - 1; // copy update files from one computer to others
            time++;
        }

        cout << time << endl;
    }

    return 0;
}