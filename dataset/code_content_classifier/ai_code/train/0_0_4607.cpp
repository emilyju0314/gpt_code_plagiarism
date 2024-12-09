#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        string a, b;
        cin >> a >> b;
        
        vector<int> freq_a(20, 0);
        vector<int> freq_b(20, 0);
        vector<int> common(20, 0);
        
        for(int i = 0; i < n; i++) {
            freq_a[a[i] - 'a']++;
            freq_b[b[i] - 'a']++;
            if(a[i] != b[i]) {
                common[a[i]-'a']++;
                common[b[i]-'a']++;
            }
        }
        
        int moves = 0;
        bool possible = true;
        
        for(int i = 0; i < 20; i++) {
            if((freq_a[i] + freq_b[i] - common[i]) % 2 != 0) {
                possible = false;
                break;
            }
            moves += common[i] / 2;
        }
        
        if(possible) {
            cout << moves << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}