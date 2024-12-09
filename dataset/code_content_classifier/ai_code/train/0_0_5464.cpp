#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long max_cost = 0;
    long long prefix_sum = 0;
    long long min_prefix_sum = 0;
    
    for(int i = 0; i < n; i++) {
        prefix_sum += a[i];
        if(i >= k) {
            prefix_sum -= a[i - k];
            min_prefix_sum = min(min_prefix_sum, prefix_sum);
        }
        if(i >= k - 1) {
            max_cost = max(max_cost, prefix_sum - min_prefix_sum - min_prefix_sum * k);
        }
    }
    
    cout << max_cost << endl;
    
    return 0;
}