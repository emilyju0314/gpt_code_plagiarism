#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<int> ans(n, 1);
    for (int k = 2; k <= n; k++) {
        // Initialize a map to store the frequency of each color in the subarray
        unordered_map<int, int> freq;
        
        int distinct_colors = 0, groups = 1;
        for (int i = 0, j = 0; j < n; j++) {
            if (freq[colors[j]] == 0) {
                distinct_colors++;
            }
            freq[colors[j]]++;
            
            while (distinct_colors > k) {
                freq[colors[i]]--;
                if (freq[colors[i]] == 0) {
                    distinct_colors--;
                }
                i++;
            }
            
            if (j == n - 1 || freq[colors[j + 1]] == 0 || distinct_colors == k) {
                ans[k - 1] = groups;
                groups++;
                freq.clear();
                distinct_colors = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}