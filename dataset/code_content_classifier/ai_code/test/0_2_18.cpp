#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int steps = n;
        int cycle = min(d, n - d);

        for(int i = 0; i < cycle; i++) {
            vector<int> new_a(n);
            for(int j = 0; j < n; j++) {
                new_a[j] = a[(j + n - d) % n];
            }

            bool all_zeros = true;
            for(int j = 0; j < n; j++) {
                a[j] &= new_a[j];
                if(a[j] != 0) all_zeros = false;
            }

            if(all_zeros) {
                steps = i + 1;
                break;
            }
        }

        if(steps < n) {
            cout << steps << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}