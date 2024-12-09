#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 101;
const int MAX_M = 51;

ll comb[MAX_M][MAX_M];
double p[MAX_N];
int t[MAX_N],v[MAX_N];
double bp[MAX_N][MAX_M];
double prt[MAX_N];
double ans[MAX_N];

int main()
{
    int n,m,L;
	cin >> n >> m >> L;
	rep(i,n){
        cin >> p[i] >> t[i] >> v[i];
        p[i] /= 100.0;
	}
    comb[0][0] = 1;
    for(int i = 1;i<=m;i++){
        comb[i][0] = 1;
        for(int j=1;j<=i;j++){
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    rep(i,n){
        if(v[i] == 0){
            prt[i] = INF;
        }else{
            prt[i] = (double)L / v[i];
        }
    }
    rep(i,n){
        rep(j,m+1){
            bp[i][j] = 1.0;
            bp[i][j] *= comb[m][j];
            rep(k,j){
                bp[i][j] *= p[i];
            }
            rep(k,m-j){
                bp[i][j] *= (1.0 - p[i]);
            }
        }
    }
    rep(i,n){
        bool flag = false;
        ans[i] = 0.0;
        rep(j,m+1){
            double tm = bp[i][j];
            rep(k,n){
                double sm = 0.0;
                if(k != i){
                    if(prt[i] + j*t[i] >= prt[k]){
                        if(t[k] == 0){
                            flag = true;
                            break;
                        }
                        int c = (int)((prt[i] + j*t[i] - prt[k] + EPS) / t[k]) + 1;
                        if(c > m){
                            flag = true;
                            break;
                        }
                        for(int l=c;l<=m;l++){
                            sm += bp[k][l];
                        }
                    }else{
                        sm = 1.0;
                    }
                    tm *= sm;
                }
            }
            if(flag){
                break;
            }
            ans[i] += tm;
        }
        printf("%.10lf\n",ans[i]);
    }
	return 0;
}