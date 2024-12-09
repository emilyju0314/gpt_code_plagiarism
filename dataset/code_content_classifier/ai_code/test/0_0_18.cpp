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

        int steps = 1;
        bool all_zeros = count(a.begin(), a.end(), 1) == 0;

        vector<int> b(n); 

        while(!all_zeros) {
            for(int i = 0; i < n; i++) {
                b[(i + d) % n] = a[i] & a[(i + d) % n];
            }

            if(count(b.begin(), b.end(), 1) == 0) {
                all_zeros = true;
                break;
            }

            a = b;
            steps++;
        }

        if(all_zeros) {
            cout << steps << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}