#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        long long sum = 0, prod = 1;
        for(int j = i; j < n; j++) {
            sum += a[j];
            prod *= a[j];
            if(prod % sum == 0 && prod / sum == k) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}