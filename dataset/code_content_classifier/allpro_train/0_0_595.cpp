#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Artist {
    string name;
    int cost;
    int satisfaction;
};

int main() {
    int LIMIT, N, M, X;

    while(cin >> LIMIT >> N >> M >> X) {
        if(LIMIT == 0 && N == 0 && M == 0 && X == 0) {
            break;
        }
        
        vector<Artist> secretArtists(N);
        vector<Artist> standardArtists(M);
        
        for(int i = 0; i < N; i++) {
            cin >> secretArtists[i].name >> secretArtists[i].cost >> secretArtists[i].satisfaction;
        }
        
        for(int i = 0; i < M; i++) {
            cin >> standardArtists[i].name >> standardArtists[i].cost >> standardArtists[i].satisfaction;
        }
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(LIMIT+1, 0)));
        
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= M; j++) {
                for(int k = 0; k <= LIMIT; k++) {
                    dp[i][j][k] = dp[i-1][j][k];
                    if(k >= secretArtists[i-1].cost) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k - secretArtists[i-1].cost] + secretArtists[i-1].satisfaction);
                    }
                }
            }
        }
        
        for(int i = 0; i <= N; i++) {
            for(int j = X; j <= M; j++) {
                for(int k = 0; k <= LIMIT; k++) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                    if(k >= standardArtists[j-1].cost) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k - standardArtists[j-1].cost] + standardArtists[j-1].satisfaction);
                    }
                }
            }
        }
        
        cout << dp[N][M][LIMIT] << endl;
    }
    
    return 0;
}