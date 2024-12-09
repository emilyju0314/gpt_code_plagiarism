#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        
        long long sum = 0;
        long long moves = 0;
        
        for(int i=0; i<n; i++) {
            if(a[i] % k != 0) {
                long long x = (a[i] + k - 1) / k;
                sum += x*k;
                moves += x;
            }
        }
        
        cout << moves << endl;
    }

    return 0;
}