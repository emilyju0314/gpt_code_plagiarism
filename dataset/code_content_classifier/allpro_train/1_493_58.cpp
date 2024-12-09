#include<bits/stdc++.h>
using namespace std;

long long int N, M, a, S, ans;
unordered_map<long long, long long> m;

int main(){
    cin >> N >> M;
    m[0] = 1;
    for(int i = 1; i <= N; ++i){
        cin >> a;
        S += a;
        S %= M;
        ans += m[S]++;
    }
    cout << ans << endl;
    return 0;
}