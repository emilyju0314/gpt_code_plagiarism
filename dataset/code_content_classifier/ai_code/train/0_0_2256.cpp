#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    
    int a = 0, b = 0;
    for(char c : s) {
        if(c == 'a') a++;
        else b++;
    }
    for(char c : t) {
        if(c == 'a') a++;
        else b++;
    }
    
    if(a % 2 == 0 && b % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<pair<int, int>> operations;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') a--;
        else b--;
        
        if(a % 2 == 0 && b % 2 == 0) {
            cout << cnt + 1 << endl;
            for(int j = 0; j < cnt; j++) {
                cout << operations[j].first << " " << operations[j].second << endl;
            }
            cout << i+1 << " 0" << endl;
            return 0;
        }
        
        cnt++;
        operations.push_back({i+1, 0});
    }
    
    int cur_b = 0;
    for(int i = 0; i < m; i++) {
        if(t[i] == 'a') a--;
        else {
            b--;
            cur_b++;
        }
        
        if(a % 2 == 0 && b % 2 == 0) {
            cout << cnt + 1 << endl;
            for(int j = 0; j < cnt; j++) {
                cout << operations[j].first << " " << operations[j].second << endl;
            }
            cout << n << " " << i+1-cur_b << endl;
            return 0;
        }
        
        cnt++;
        operations.push_back({n, i+1-cur_b});
    }
    
    return 0;
}