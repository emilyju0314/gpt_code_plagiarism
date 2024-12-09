#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> t;
vector<vector<double>> dp;

double solve(int level, int regions) {
    if (dp[level][regions] > -1) {
        return dp[level][regions];
    }
    
    if (regions == 1) {
        double sum = 0;
        for (int i = level; i < t.size(); i++) {
            sum += t[i];
        }
        return dp[level][regions] = sum / t.size();
    }
    
    double min_hours = numeric_limits<double>::max();
    double sum = 0;
    
    for (int i = level; i < t.size() - regions + 1; i++) {
        sum += t[i];
        min_hours = min(min_hours, (sum / (i - level + 1)) + solve(i+1, regions - 1));
    }
    
    return dp[level][regions] = min_hours;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    t.resize(n);
    dp.resize(n, vector<double>(k+1, -1));
    
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    cout << fixed;
    cout.precision(10);
    cout << solve(0, k) << endl;
    
    return 0;
}