#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> flights; // pair of cost and index
    vector<int> delays(n);
    
    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        flights.push_back({cost, i});
    }
    
    sort(flights.begin(), flights.end(), greater<pair<int, int>>()); // sort flights by cost
    
    long long totalCost = 0;
    
    for (int i = 0; i < n; i++) {
        int departureTime = k + i + 1;
        int index = flights[i].second;
        totalCost += (long long) flights[i].first * (departureTime - index);
        delays[index] = departureTime;
    }
    
    cout << totalCost << endl;
    
    for (int i = 0; i < n; i++) {
        cout << delays[i] << " ";
    }
    
    return 0;
}