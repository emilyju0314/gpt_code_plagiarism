#include <bits/stdc++.h>
using namespace std;

char get_next_char(char c, int k) {
    return (c - 'a' + 1) % k + 'a';
}

char get_prev_char(char c, int k) {
    return (c - 'a' - 1 + k) % k + 'a';
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        for(int i = 0; i < n; i++) {
            char min_char = s[i];
            for(int j = max(0, i - 1); j <= min(i + 1, n - 1); j++) {
                char curr_char = s[j];
                char prev_char = get_prev_char(curr_char, k);
                char next_char = get_next_char(curr_char, k);
                
                if (j - 1 >= 0 && curr_char > s[j - 1]) {
                    min_char = min(min_char, s[j - 1]);
                }
                if (j + 1 < n && curr_char > s[j + 1]) {
                    min_char = min(min_char, s[j + 1]);
                }
                if (curr_char > prev_char) {
                    min_char = min(min_char, prev_char);
                }
                if (curr_char > next_char) {
                    min_char = min(min_char, next_char);
                }
            }
            s[i] = min_char;
        }
        
        cout << s << endl;
    }
    
    return 0;
}