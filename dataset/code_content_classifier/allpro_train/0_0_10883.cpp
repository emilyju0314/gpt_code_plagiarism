#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> ans(k, 0);
    
    int i = 0;
    while (n > 0 && i < k) {
        long long len = 1;
        while ((1LL << len) <= n) {
            len++;
        }
        len--;
        
        ans[i] = len;
        n -= (1LL << len);
        i++;
    }

    if (n == 0 && i == k) {
        cout << "Yes" << endl;
        for (int j = 0; j < k; j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}