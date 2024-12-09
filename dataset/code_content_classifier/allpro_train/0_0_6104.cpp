#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> seq(n);
    unordered_map<int, int> freq;
    
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
        freq[seq[i]]++;
    }

    sort(seq.rbegin(), seq.rend());

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int a = seq[i];
            int b = seq[j];
            int len = 2;
            
            freq[a]--;
            freq[b]--;
            
            while(freq.count(a + b) && freq[a + b] > 0) {
                b = a + b;
                a = b - a;
                len++;
                freq[b]--;
            }

            ans = max(ans, len);

            while(len > 2) {
                b = a - b;
                a = b + a;
                freq[a]++;
                len--;
            }

            freq[seq[i]]++;
            freq[seq[j]]++;
        }
    }

    cout << ans << endl;

    return 0;
}