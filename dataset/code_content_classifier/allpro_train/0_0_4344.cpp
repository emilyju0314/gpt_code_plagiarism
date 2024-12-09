#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Transformer {
    int x, y, d, t, e;
};

bool compare(Transformer a, Transformer b) {
    return a.t < b.t;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<Transformer> transformers(K);
    
    for(int i=0; i<K; i++) {
        cin >> transformers[i].x >> transformers[i].y >> transformers[i].d >> transformers[i].t >> transformers[i].e;
    }
    
    sort(transformers.begin(), transformers.end(), compare);
    
    vector<vector<int>> dp(N, vector<int>(M, 1e9));
    
    dp[0][0] = 0;
    
    for(int i=0; i<K; i++) {
        for(int j=0; j<4; j++) {
            int x = transformers[i].x;
            int y = transformers[i].y;
            int e = transformers[i].e;
            for(int t=0; t<=transformers[i].t; t++) {
                if(x >= 0 && x < N && y >= 0 && y < M) {
                    dp[x][y] = min(dp[x][y], max(dp[x][y], dp[max(0, x-transformers[i].d)][max(0, y-transformers[i].d)]) + e);
                }
                
                if(j == 0) {
                    x = transformers[i].x;
                    y = transformers[i].y;
                }
                else if(j == 1) {
                    x = x + transformers[i].d;
                    y = y - transformers[i].d;
                }
                else if(j == 2) {
                    x = x + transformers[i].d;
                }
                else {
                    y = y + transformers[i].d;
                }
            }
        }
    }
    
    cout << dp[N-1][M-1] << endl;
    
    return 0;
}