#include <iostream>
#include <vector>
#define M 998244353

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 1;
    
    for(int i = 0; i < n; i++) {
        if (a[i] == -1) {
            int l = i > 0 ? a[i-1] : 1;
            int r = i < n-1 ? a[i+1] : 200;
            for(int j = l; j <= r; j++) {
                bool valid = true;
                if (i > 0 && a[i-1] > j) valid = false;
                if (i < n-1 && a[i+1] > j) valid = false;
                if (valid) ans = (ans*1LL*j) % M;
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}