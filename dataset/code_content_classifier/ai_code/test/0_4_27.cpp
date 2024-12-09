#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        // If m is less than n-1 or m is greater than n*(n-1)/2, then it is impossible to create the graph
        if(m < n-1 || m > n*(n-1)/2) {
            cout << "NO\n";
            continue;
        }

        // If the diameter can be less than k-1, then it is possible to create the graph
        if(k >= 3) {
            cout << "YES\n";
        } else {
            if(n == 1 || m == n-1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}