#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    
    vector<int> pref(p.size());
    
    for(int i = 0; i < s.size(); i++) {
        int match = 0;
        for(int j = 0; j < s.size() - i; j++) {
            if(s[i + j] == p[match])
                match++;
            if(match == p.size())
                pref[j + 1]++;
        }
    }
    
    for(int i = int(s.size()) - 1; i > 0; i--)
        pref[i - 1] += pref[i];
    
    for(int i = 0; i <= s.size(); i++)
        cout << pref[i] << " ";
    
    return 0;
}