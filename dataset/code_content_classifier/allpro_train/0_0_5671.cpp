#include <iostream>
#include <iomanip>

using namespace std;

double dp[101][101][101];

int main() {
    int r, s, p;
    cin >> r >> s >> p;

    dp[r][s][p] = 1.0;
    
    for(int rock = r; rock >= 0; rock--) {
        for(int scissor = s; scissor >= 0; scissor--) {
            for(int paper = p; paper >= 0; paper--) {
                int total_groups = rock * scissor + scissor * paper + paper * rock;
                
                if(rock > 0 && scissor > 0) {
                    dp[rock-1][scissor][paper] += (dp[rock][scissor][paper] * (double)(rock * scissor)) / total_groups;
                }
                if(scissor > 0 && paper > 0) {
                    dp[rock][scissor-1][paper] += (dp[rock][scissor][paper] * (double)(scissor * paper)) / total_groups;
                }
                if(rock > 0 && paper > 0) {
                    dp[rock][scissor][paper-1] += (dp[rock][scissor][paper] * (double)(paper * rock)) / total_groups;
                }
            }
        }
    }

    double total_rock = 0, total_scissor = 0, total_paper = 0;
    for(int i = 0; i <= r; i++) {
        total_rock += dp[i][0][0];
    }
    for(int i = 0; i <= s; i++) {
        total_scissor += dp[0][i][0];
    }
    for(int i = 0; i <= p; i++) {
        total_paper += dp[0][0][i];
    }

    cout << fixed << setprecision(12) << total_rock << " " << total_scissor << " " << total_paper << endl;
    
    return 0;
}