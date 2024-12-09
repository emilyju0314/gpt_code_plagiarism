#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int m;
    cin >> m;
    
    vector<pair<int, string>> prices;
    for (int i = 0; i < m; i++) {
        int cost;
        string port;
        cin >> cost >> port;
        prices.push_back(make_pair(cost, port));
    }
    
    sort(prices.begin(), prices.end());
    
    int num_equipped = 0;
    int total_cost = 0;
    
    for (int i = 0; i < m; i++) {
        if (prices[i].second == "USB" && a > 0) {
            num_equipped++;
            total_cost += prices[i].first;
            a--;
        } else if (prices[i].second == "PS/2" && b > 0) {
            num_equipped++;
            total_cost += prices[i].first;
            b--;
        } else if (c > 0) {
            num_equipped++;
            total_cost += prices[i].first;
            c--;
        }
    }
    
    cout << num_equipped << " " << total_cost << endl;
    
    return 0;
}