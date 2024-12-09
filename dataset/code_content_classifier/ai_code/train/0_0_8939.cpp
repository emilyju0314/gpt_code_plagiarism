#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> array(n);
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        unordered_map<int, int> count;
        int mostFreq = 0;
        int mostFreqCount = 0;
        int otherFreqCount = 0;
        
        for(int j = i; j < n; j++) {
            count[array[j]]++;
            if(count[array[j]] > mostFreqCount) {
                mostFreqCount = count[array[j]];
                mostFreq = array[j];
            }
        }
        
        for(auto &p : count) {
            if(p.second == mostFreqCount) {
                otherFreqCount++;
            }
        }
        
        if(otherFreqCount > 1) {
            maxLen = max(maxLen, j - i + 1);
        }
    }
    
    cout << maxLen << endl;
    
    return 0;
}