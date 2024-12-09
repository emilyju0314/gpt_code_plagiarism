#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d, x;
    cin >> n >> d >> x;
    
    vector<vector<int>> p(d, vector<int>(n));
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    
    int money = x;
    for(int i = 0; i < d; i++) {
        int max_profit = 0;
        for(int j = 0; j < n; j++) {
            int profit = p[i][j] - 1;
            if(profit > 0) {
                int units = money / p[i][j];
                int total_profit = profit * units;
                if(total_profit > max_profit) {
                    max_profit = total_profit;
                }
            }
        }
        money += max_profit;
    }
    
    cout << money << endl;
    
    return 0;
}