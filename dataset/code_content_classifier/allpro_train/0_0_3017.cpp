#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, D, W, X;
vector<vector<int>> E, F;

int dp[31][16][51][6];

int solve(int day, int region, int burden, int duplicates) {
    if(burden > W || duplicates > X) return 0;
    if(day == D) return 0;
    
    if(dp[day][region][burden][duplicates] != -1) {
        return dp[day][region][burden][duplicates];
    }
    
    int max_profit = 0;
    for(int i = 0; i < C; i++) {
        if(E[i][day] == 0) continue;
        
        int profit = E[i][day] - F[i][day];
        if(region != i) profit = max_profit;
        
        if(region != i) {
            max_profit = max(max_profit, profit + solve(day+1, i, burden + F[i][day], day == 0 ? duplicates : (region == i ? duplicates + 1 : 1));
        } else {
            max_profit = max(max_profit, profit + solve(day+1, i, burden + F[i][day], duplicates));
        }
    }
    
    dp[day][region][burden][duplicates] = max_profit;
    return max_profit;
}

int main() {
    while(true) {
        cin >> C >> D >> W >> X;
        if(C == 0 && D == 0 && W == 0 && X == 0) break;
        
        E.assign(C, vector<int>(D));
        F.assign(C, vector<int>(D));
        
        for(int i = 0; i < C; i++) {
            for(int j = 0; j < D; j++) {
                cin >> E[i][j];
            }
        }
        
        for(int i = 0; i < C; i++) {
            for(int j = 0; j < D; j++) {
                cin >> F[i][j];
            }
        }
        
        memset(dp, -1, sizeof(dp));
        
        int max_profit = 0;
        for(int i = 0; i < C; i++) {
            max_profit = max(max_profit, solve(0, i, 0, 0));
        }
        
        cout << max_profit << endl;
    }
    return 0;
}