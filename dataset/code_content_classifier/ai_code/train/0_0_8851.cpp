#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = 0;
    
    // Try every possible value to be the most frequent value
    for(int val = 1; val <= 100; val++) {
        int mostFreq = 0;
        int secondMostFreq = 0;
        unordered_map<int, int> freq;
        int l = 0, r = 0;
        
        while(r < n) {
            freq[arr[r]]++;
            mostFreq = max(mostFreq, freq[arr[r]]);
            secondMostFreq = max(secondMostFreq, min(freq[arr[r]], mostFreq - 1));
            
            if(r - l + 1 - mostFreq > secondMostFreq) {
                freq[arr[l]]--;
                l++;
            }
            
            ans = max(ans, r - l + 1);
            r++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}