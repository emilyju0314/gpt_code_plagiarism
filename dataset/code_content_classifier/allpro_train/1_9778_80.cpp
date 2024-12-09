#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
    int N;
    string s,t;
    cin >> N >> s >> t;
    vector<int> cnt(26,0);
    cnt[s[0]-'a'] = 1;
    int i;
    for(i=1;i<N-1;i++)cnt[s[i]-'a'] = (cnt[s[i]-'a']+cnt[t[i]-'a'])%1000000007;
    cout << cnt[t[N-1]-'a'] << endl;
}
