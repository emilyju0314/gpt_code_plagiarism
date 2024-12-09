#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = 1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) {
            int left = (i == 0) ? 1 : arr[i-1];
            int right = (i == n-1) ? 1 : arr[i+1];
            int possible_values = 0;

            for(int j = 1; j <= 200; j++) {
                if(j >= left && j <= right) {
                    possible_values++;
                }
            }

            ans = (ans * possible_values) % MOD;
        }
    }

    cout << ans << endl;
    
    return 0;
}