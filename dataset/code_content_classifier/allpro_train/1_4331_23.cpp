#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[61][61][3001];

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N+1),R(K+1),B(K+1);
    int sumA = 0,sumR = 0,sumB = 0;
    for(int i=1;i<=N;i++){
        cin >> A[i];
        sumA += A[i];
    }
    for(int i=1;i<=K;i++){
        cin >> R[i];
        sumR += R[i];
    }
    for(int i=1;i<=K;i++){
        cin >> B[i];
        sumB += B[i];
    }
    sort(A.begin()+1,A.end(),greater<int>());
    sort(R.begin()+1,R.end(),greater<int>());
    sort(B.begin()+1,B.end(),greater<int>());
    for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) for(int k=0;k<=3000;k++) dp[i][j][k] = 1e9;
    dp[0][0][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=i;j++){
            int rid = j,bid = i-j;
            for(int k=0;k<=3000;k++){
                if(1<=rid && rid<=K && k+A[i]<=3000){
                    dp[i][rid][k+A[i]] = min(dp[i][rid][k+A[i]],dp[i-1][rid-1][k]+max(0,A[i]-R[rid]));
                }
                if(1<=bid && bid<=K){
                    dp[i][i-bid][k] = min(dp[i][i-bid][k],dp[i-1][i-bid][k]+max(0,A[i]-B[bid]));
                }
            }
        }
    }
    int inf = 1e9;
    int res = inf;
    for(int j=0;j<=N;j++){
        for(int k=0;k<=3000;k++){
            int useR = k,useB = sumA-k;
            if(useR<=sumR && useB<=sumB) res = min(res,dp[N][j][k]);
        }
    }
    cout << (res!=inf? res:-1) << endl;
}
