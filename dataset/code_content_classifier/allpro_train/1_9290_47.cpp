#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int t;
    cin >> t;
    vector< long long > a(200000), dp(200000);
    while(t--){
        int n;
        cin >> n;
        vector< int > a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        long long ans = 0;
        for(int i=0;i<n;i++){
            if((a[i]+i)%2 == 0) ans += (i%2 == 0 ? a[i] : -a[i]);
        }
        puts(ans > 0 ? "Alice" : ans < 0 ? "Bob" : "Tie");
    }
}
