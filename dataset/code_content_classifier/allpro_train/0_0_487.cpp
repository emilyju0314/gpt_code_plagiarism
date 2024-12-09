#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

double calculateProbability(Point A, Point B, Point C) {
    int distAB = abs(B.x - A.x) + abs(B.y - A.y);
    int distAC = abs(C.x - A.x) + abs(C.y - A.y);
    
    if (distAB == 0) return (distAC == 0) ? 1.0 : 0.0;
    
    return 1.0 / (double)distAB;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<vector<double>> prob(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prob[i][j] = calculateProbability(points[i], points[j], points[(j+1)%n]); 
        }
    }
    
    int q;
    cin >> q;
    
    for (int k = 0; k < q; k++) {
        int t, m;
        cin >> t >> m;
        t--;
        
        vector<vector<double>> dp(m+1, vector<double>(n, 0.0));
        dp[0][t] = 1.0;
        
        for (int i = 1; i <= m; i++) {
            vector<double> sum(n, 0.0);
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    sum[j] += dp[i-1][l] * prob[l][j];
                }
            }
            for (int j = 0; j < n; j++) {
                dp[i][j] = sum[j];
            }
        }
        
        cout << fixed << setprecision(20) << dp[m][t] << endl;
    }
    
    return 0;
}