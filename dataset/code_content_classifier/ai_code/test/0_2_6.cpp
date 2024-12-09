#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long totalPrettiness = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            totalPrettiness = (totalPrettiness + (long long)gcd(arr[i], arr[j]) * gcd(i+1, j+1)) % MOD;
        }
    }
    
    cout << totalPrettiness << endl;
    
    return 0;
}