#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d, m;
    cin >> n >> d >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    vector<int> small, large;
    for(int i = 0; i < n; i++) {
        if(a[i] <= m) {
            small.push_back(a[i]);
        } else {
            large.push_back(a[i]);
        }
    }
    
    long long result = 0;
    
    int num_small = small.size();
    int num_large = large.size();
    
    vector<long long> prefix_sum_small(num_small + 1, 0);
    for(int i = 1; i <= num_small; i++) {
        prefix_sum_small[i] = prefix_sum_small[i-1] + small[i-1];
    }
    
    if(num_large == 0) {
        result = prefix_sum_small[num_small];
    } else {
        int num_large_used = min((n - 1) / (d + 1) + 1, num_large);
        long long sum_large = 0;
        for(int i = 0; i < num_large; i++) {
            sum_large += large[i];
        }
        
        for(int num_small_used = max(0, num_large_used - 1); num_small_used <= min(num_small, num_large_used * d); num_small_used++) {
            long long current_sum = prefix_sum_small[num_small_used];
            current_sum += sum_large;
            int remaining_small = num_small - num_small_used;
            if(remaining_small >= 0) {
                int remaining_large = num_large - num_large_used;
                if(remaining_large >= 0) {
                    int remaining_muzzled = n - num_small_used - num_large_used;
                    if(remaining_muzzled > 0) {
                        if(remaining_small >= min(remaining_large, remaining_muzzled)) {
                            current_sum += prefix_sum_small[remaining_small] - prefix_sum_small[max(0, remaining_small - remaining_large)];
                        }else {
                            current_sum += prefix_sum_small[remaining_small];
                        }
                    }
                } else {
                    current_sum += prefix_sum_small[remaining_small];
                }
            }
            result = max(result, current_sum);
        }
    }
    
    cout << result << endl;
    
    return 0;
}