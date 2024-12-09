#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        string a, b;
        cin >> a >> b;
        
        vector<int> freqA(26), freqB(26);
        
        for (char c : a) {
            freqA[c-'a']++;
        }
        
        for (char c : b) {
            freqB[c-'a']++;
        }
        
        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (freqB[i] > freqA[i] || (freqA[i] - freqB[i]) % k != 0) {
                possible = false;
                break;
            }
            if (i < 25) {
                freqA[i+1] += freqA[i] - freqB[i]; // simulate increment operation
            }
        }
        
        cout << (possible ? "Yes" : "No") << endl;
    }
    
    return 0;
}