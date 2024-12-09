#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    
    vector<int> counts(26, 0);
    for(char c : s) {
        counts[c - 'A']++;
    }
    
    int q;
    cin >> q;
    
    while(q--) {
        int x, y;
        cin >> x >> y;
        
        x--; y--;
        
        if(x > y) {
            swap(x, y);
        }
        
        int count_x = counts[s[x] - 'A'];
        int count_y = counts[s[y] - 'A'];
        
        int half = n / 2;
        int valid_arrangements = 2;
        
        if(count_x <= half && count_y <= half) {
            valid_arrangements = 0;
        } else if(count_x > half && count_y > half) {
            valid_arrangements = 0;
        } else {
            for(int i = 0; i < 26; i++) {
                if(s[x] - 'A' == i || s[y] - 'A' == i) {
                    continue;
                }
                int count = counts[i];
                if(count_x + count_y - count <= half && count_x + count_y >= half) {
                    valid_arrangements = 1;
                    break;
                }
            }
        }
        
        if(valid_arrangements == 0) {
            cout << "0\n";
        } else {
            long long ans = 1;
            for(int i = 1; i <= n/2 - max(count_x, count_y); i++) {
                ans = (ans * i) % MOD;
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}