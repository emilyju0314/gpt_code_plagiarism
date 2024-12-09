#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> stones(n);
    for(int i=0; i<n; i++) {
        cin >> stones[i];
    }

    vector<long long> sortedStones = stones;
    sort(sortedStones.begin(), sortedStones.end());

    vector<long long> prefixSum(n+1);
    for(int i=1; i<=n; i++) {
        prefixSum[i] = prefixSum[i-1] + stones[i-1];
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        
        if(type == 1) {
            cout << prefixSum[r] - prefixSum[l-1] << endl;
        } else {
            cout << (sortedStones[r-1] - sortedStones[l-1] + stones[l-1] * (r-l)) << endl;
        }
    }

    return 0;
}