#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int g(vector<int>& a, int i, int j) {
    int sum = 0;
    for (int k = min(i, j) + 1; k <= max(i, j); k++) {
        sum += a[k];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                int fi_j = pow(i - j, 2) + pow(g(a, i, j), 2);
                ans = min(ans, fi_j);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}