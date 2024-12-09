#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

long long f(int x, int y) {
    string xs = to_string(x);
    string ys = to_string(y);
    reverse(xs.begin(), xs.end());
    reverse(ys.begin(), ys.end());
    
    string result = "";
    int p = xs.size();
    int q = ys.size();
    int i = 0, j = 0;
    
    while (i < p || j < q) {
        if (i < p) {
            result += xs[i];
            i++;
        }
        if (j < q) {
            result += ys[j];
            j++;
        }
    }
    
    reverse(result.begin(), result.end());
    
    return stoll(result);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = (ans + f(nums[i], nums[j])) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}