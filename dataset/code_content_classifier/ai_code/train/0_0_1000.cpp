#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefixXor(n);
    prefixXor[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefixXor[i] = prefixXor[i-1] ^ a[i];
    }

    unordered_map<int, int> countXor;
    countXor[0] = 1;
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int currXor = l > 0 ? prefixXor[r] ^ prefixXor[l-1] : prefixXor[r];

        ans = 0;
        if(countXor.find(currXor ^ k) != countXor.end()) {
            ans += countXor[currXor ^ k];
        }
        
        countXor[currXor]++;
        
        cout << ans << endl;
    }

    return 0;
}