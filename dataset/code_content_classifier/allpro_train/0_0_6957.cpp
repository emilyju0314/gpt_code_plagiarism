#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    string x;
    cin >> x;

    int n = x.size();
    vector<int> ones(n+1);
    for(int i = 0; i < n; i++) {
        ones[i+1] = ones[i] + (x[i] == '1');
    }

    int result = 0;
    for(int i = 0; i <= n; i++) {
        result = (result + min(i, n-i) + ones[i]) % MOD;
    }

    cout << result << endl;

    return 0;
}