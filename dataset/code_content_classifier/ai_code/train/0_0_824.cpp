#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        if(isPrime(arr[i])) {
            ans = min(ans, b);
        } else {
            for(int j = max(2, arr[i]-1); j <= arr[i]+1; j++) {
                int cost = 0;
                for(int k = 0; k < n; k++) {
                    int diff = abs(arr[k] - j);
                    cost += diff * a;
                }
                ans = min(ans, cost);
            }
        }
    }

    cout << ans << endl;

    return 0;
}