#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    // Iterate through all possible most frequent values
    for(int most_freq = 1; most_freq <= n; most_freq++) {
        unordered_map<int, int> freq_count;
        int left = 0, max_freq = 0, unique_values = 0;

        // Sliding window approach to find the longest subarray
        for(int right = 0; right < n; right++) {
            freq_count[arr[right]]++;
            max_freq = max(max_freq, freq_count[arr[right]]);
            unique_values = max(unique_values, freq_count.size());

            // If there are more than one value occurring max_freq times
            // in the subarray, update the answer
            if(right - left + 1 - max_freq > max_freq) {
                ans = max(ans, right - left);
                freq_count[arr[left]]--;
                if(freq_count[arr[left]] == 0) {
                    freq_count.erase(arr[left]);
                }
                left++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}