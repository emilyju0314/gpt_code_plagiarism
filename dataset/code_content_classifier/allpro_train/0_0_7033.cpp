#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> tags(n);
        for(int i = 0; i < n; i++) {
            cin >> tags[i];
        }

        vector<int> freq(n+1, 0);
        for(int tag : tags) {
            freq[tag]++;
        }

        int max_freq = *max_element(freq.begin(), freq.end());
        int total_freq = accumulate(freq.begin(), freq.end(), 0) - max_freq;

        int result = max(total_freq - max_freq + 1, 0);

        if(result == 0) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}