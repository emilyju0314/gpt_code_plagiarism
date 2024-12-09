#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c-'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int min_max = freq[0];
        for(int i = 1; i < k; i++) {
            min_max = max(min_max, freq[i]);
        }

        cout << (char)('a' + min_max - 1) << endl;
    }

    return 0;
}