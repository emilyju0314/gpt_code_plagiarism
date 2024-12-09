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

        vector<int> b(n);
        long long total_sum = 0;
        for(int i=0; i<n; i++) {
            cin >> b[i];
            total_sum += b[i];
        }

        vector<int> a(n);
        bool possible = true;
        long long sum_k = 0;
        for(int i=0; i<n; i++) {
            sum_k += b[i];
            a[i] = (i+1) * (total_sum - sum_k);
            if(a[i] <= 0 || (i > 0 && a[i] <= a[i-1])) {
                possible = false;
                break;
            }
        }

        if(possible) {
            cout << "YES" << endl;
            for(int i=0; i<n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}