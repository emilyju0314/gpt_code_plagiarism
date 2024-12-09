#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int N, M, Q;
vector<vector<pair<int, int>>> shops;
vector<vector<int>> restrictions;
vector<long long> A;

long long dp[60][550];

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int K;
        cin >> K;
        vector<pair<int, int>> shop;
        
        for(int j = 0; j < K; j++) {
            int S, P, C;
            cin >> S >> P >> C;
            shop.push_back({S, P});
        }
        
        shops.push_back(shop);
    }
    
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        restrictions.push_back({U, V, W});
    }
    
    cin >> Q;
    
    for(int i = 0; i < Q; i++) {
        long long Ai;
        cin >> Ai;
        A.push_back(Ai);
    }
    
    for(int i = 0; i < 60; i++) {
        for(int j = 0; j < 550; j++) {
            dp[i][j] = LLONG_MAX;
        }
    }
    
    dp[0][0] = 0;
    
    for(int i = 1; i <= Q; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 0; k < shops[j - 1].size(); k++) {
                int Sj = shops[j - 1][k].first;
                int Pj = shops[j - 1][k].second;
                
                for(int l = 0; l < restrictions.size(); l++) {
                    int U = restrictions[l][0];
                    int V = restrictions[l][1];
                    int W = restrictions[l][2];
                    
                    if(dp[i - 1][V] != LLONG_MAX && dp[i - 1][V] + Pj <= A[i - 1] && dp[i - 1][V] + Pj < dp[i][U] + Pj + W) {
                        dp[i][U] = dp[i - 1][V] + Pj;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < Q; i++) {
        if(dp[i + 1][1] == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << dp[i + 1][1] << endl;
        }
    }
    
    return 0;
}