#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> from;
    vector<int> to;
    for(int i = 1; i <= N; i++){
        int a; cin >> a;
        if(i < a){
            from.push_back(i);
            to.push_back(a);
        }
    }
    int ans = 0;
    for(int s = 0; s < from.size(); s++){
        vector<int> dp(from.size() + 1, INF);
        dp[0] = dp[1] = to[s];
        int max_k = 1;
        for(int i = s + 1; i < from.size(); i++){
            if(from[i] >= to[s]) break;
            int k = upper_bound(dp.begin(), dp.end(), to[i]) - dp.begin();
            //printf("s = %d i = %d k = %d\n", s, i, k);
            if(k < 2) continue;
            dp[k] = to[i];
            max_k = max(max_k, k);
        }
        ans = max(ans, min(N / 2, max_k + K));
    }
    cout << ans << endl;
    return 0;
}