#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

const double INF = numeric_limits<double>::max();
const int MAX_L = 50;

inline void update(double& x, const double& y) {
    if(x > y) {
        x = y;
    }
}

int main(){
    int n;
    while(cin >> n && n > 0) {
        vector<double> p;
        double cnt = 0;
        REP(i, n) {
            double x;
            cin >> x;
            if(x != 1.00) {
                if(cnt > 0){
                    p.push_back(cnt);
                    cnt = 0;
                }
                p.push_back(x);
            } else {
                cnt += 1.0;
            }
        }

        if(cnt > 0) {
            p.push_back(cnt);
        }

        n = p.size();

        vector<double> dp(n + 1, INF);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            double cost = 0;
            for(int j = 0; j < MAX_L && i + j < n; j++) {
                if(p[i + j] < 1.0) {
                    cost = (cost + 1) / p[i + j];
                } else {
                    cost = (cost + p[i + j]) / 1.0;
                }
                update(dp[i + j + 1], dp[i] + cost + (i + j + 1 == n ? 0.0 : 1.0));
            }
        }

        printf("%.12f\n", dp[n]);
    }
    return 0;
}