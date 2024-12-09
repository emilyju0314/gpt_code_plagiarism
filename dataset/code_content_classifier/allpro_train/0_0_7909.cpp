#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> prices(m);
    for(int i = 0; i < m; i++) {
        int ki;
        cin >> ki;
        prices[i].resize(ki);
        for(int j = 0; j < ki; j++) {
            cin >> prices[i][j];
        }
        sort(prices[i].begin(), prices[i].end());
    }
    
    double total = 0.0;
    double count = 0.0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < prices[i].size(); j++) {
            if(prices[i].size() >= n) {
                total += 1.0 / prices[i].size();
                count += 1.0 / prices[i].size();
            } else {
                total += (1.0 / prices[i].size()) * n / prices[i].size();
                count += (1.0 / prices[i].size()) * n / prices[i].size();
            }
        }
    }
    
    cout << setprecision(9) << total / count << endl;
    
    return 0;
}