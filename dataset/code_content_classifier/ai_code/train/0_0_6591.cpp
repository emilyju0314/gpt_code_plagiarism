#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n >> s >> m;
    
    unordered_map<char, int> freq;
    for(char c : s) {
        freq[c]++;
    }
    
    for(int i = 0; i < m; i++) {
        string t;
        cin >> t;
        
        int cnt = 0;
        unordered_map<char, int> freq_t;
        for(char c : t) {
            freq_t[c]++;
        }
        
        for(char c : t) {
            if(freq[c] < freq_t[c]) {
                cnt = n+1;
                break;
            } else {
                cnt = max(cnt, freq_t[c]);
            }
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}