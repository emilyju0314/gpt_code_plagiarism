#include<bits/stdc++.h>
using namespace std;

//マクロ
#define FOR(i, a, b) for(int i = (a); i < (b), i++)
#define REP(i, n) FOR(i, 0, n);
#define ALL(a) (a).begin(),(a).end()


int main(){
    
    //入力
    int n, d, x; cin >> n >> d >> x;
    vector<vector<int> > p(d, vector<int> (n));
    for(int i = 0; i < d; i++){
        for(int j = 0; j < n; j++){
            cin >> p[i][j];
        }
    }

    int w = x;

    for(int k = 0; k < d - 1; k++){

        vector<int> weight(n);
        vector<int> value(n);
        vector<vector<int> > dp(n, vector<int> (w + 1, 0));
        for(int i = 0; i < n; i++){
            weight[i] = p[k][i];
            value[i] = p[k + 1][i] - p[k][i];
        }

        //dp
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= w; j++){
                if(i == 0){
                    if(j >= weight[i]) dp[i][j] = max(dp[i][j], dp[i][j - weight[i]] + value[i]);
                }else{
                    if(j >= weight[i]) dp[i][j] = max({dp[i][j - weight[i]] + value[i], dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]});
                    else dp[i][j] = dp[i - 1][j];
                }
            }
        }

        //cout << dp[n - 1][w] << endl;
        w += dp[n - 1][w];
    }

    cout << w << endl;

    return 0;
}
