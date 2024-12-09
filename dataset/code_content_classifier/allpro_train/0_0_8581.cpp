#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    
    map<int, int> ribbonCount;
    map<int, int> freqCount;
    
    int maxStreak = 0;
    int left = 0, right = 0;
    
    while(right < n) {
        if(ribbonCount[colors[right]] > 0) {
            freqCount[ribbonCount[colors[right]]]--;
            if(freqCount[ribbonCount[colors[right]]] == 0) {
                freqCount.erase(ribbonCount[colors[right]]);
            }
        }
        
        ribbonCount[colors[right]]++;
        freqCount[ribbonCount[colors[right]]]++;
        
        while(freqCount.size() > 2) {
            ribbonCount[colors[left]]--;
            if(ribbonCount[colors[left]] > 0) {
                freqCount[ribbonCount[colors[left]]]++;
            }
            if(freqCount[ribbonCount[colors[left]]+1] == 1) {
                freqCount.erase(ribbonCount[colors[left]]+1);
            } else {
                freqCount[ribbonCount[colors[left]]+1]--;
            }
            left++;
        }
        
        maxStreak = max(maxStreak, right - left + 1);
        right++;
    }
    
    cout << maxStreak << endl;
    
    return 0;
}