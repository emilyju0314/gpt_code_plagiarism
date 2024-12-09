#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countOnes(vector<string>& rows) {
    int n = rows.size();
    int m = rows[0].size();
    
    int ans = n;
    for(int i=0; i<(1<<n); i++) {
        int cnt = 0;
        for(int j=0; j<m; j++) {
            int ones = 0;
            for(int k=0; k<n; k++) {
                ones += rows[k][j] ^ ((i>>k) & 1);
            }
            cnt += max(ones, n - ones);
        }
        ans = min(ans, cnt);
    }
    
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> rows(n);
    for(int i=0; i<n; i++) {
        cin >> rows[i];
    }
    
    int result = countOnes(rows);
    
    cout << result << endl;
    
    return 0;
}