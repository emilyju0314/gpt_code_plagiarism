#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> x(n);
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }

        vector<int> y(n);
        int prev = 0;
        for(int i = 0; i < n; i++) {
            y[i] = prev & x[i];
            prev = (prev ^ x[i]) & ~y[i];
        }

        for(int i = 0; i < n; i++) {
            cout << y[i] << " ";
        }
        cout << endl;
    }

    return 0;
}