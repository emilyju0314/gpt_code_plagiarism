#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int computeBeauty(int n, int k, vector<int>& prices) {
    long long int ans = 0;
  
    for(int mask = 0; mask < (1 << n); mask++) {
        if(__builtin_popcount(mask) != k) continue;
      
        vector<long long int> shelves(k, 0);
        for(int i = 0; i < n; i++) {
            shelves[__builtin_ctz(mask)] += prices[i];
            mask >>= 1;
        }
      
        long long int shelfBeauty = shelves[0];
        for(int i = 1; i < k; i++) {
            shelfBeauty &= shelves[i];
        }
      
        ans = max(ans, shelfBeauty);
    }
  
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
  
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    long long int maxBeauty = computeBeauty(n, k, prices);
  
    cout << maxBeauty << endl;

    return 0;
}