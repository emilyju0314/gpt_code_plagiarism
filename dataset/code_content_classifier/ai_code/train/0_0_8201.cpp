#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> knights;
    for (int i = 0; i < n; i++) {
        int power, coins;
        cin >> power;
        knights.push_back(make_pair(power, i));
    }
    
    vector<long long> initialCoins;
    for (int i = 0; i < n; i++) {
        long long coins;
        cin >> coins;
        initialCoins.push_back(coins);
    }
    
    sort(knights.begin(), knights.end());
    
    vector<long long> maxCoins(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += initialCoins[knights[i].second];
        
        if (i >= k) {
            sum -= initialCoins[knights[i-k].second];
        }
        
        maxCoins[knights[i].second] = sum;
    }
    
    for (int i = 0; i < n; i++) {
        cout << maxCoins[i] << " ";
    }
    
    return 0;
}