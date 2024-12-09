#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    s.insert(s.begin(), 'A');
    for(int i = 0; i < n; i++) ans += s[i] >= s[i + 1];
    cout << ans << endl;
}

