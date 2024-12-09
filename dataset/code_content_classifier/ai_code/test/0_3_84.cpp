#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long c(int l, int r) {
    return (r-l+1) * (r-l+2) / 2;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> x(k+1);
        x[0] = 0;
        x[k] = n;

        for(int i = 1; i < k; i++) {
            x[i] = n*i/k;
        }

        long long ans = 0;

        for(int i = 0; i < k; i++) {
            ans += c(x[i]+1, x[i+1]);
        }

        cout << ans << endl;
    }

    return 0;
}