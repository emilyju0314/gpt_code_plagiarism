#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    
    vector<pair<int, int>> friends;
    
    for(int i = 0; i < n; i++) {
        int money, factor;
        cin >> money >> factor;
        friends.push_back(make_pair(money, factor));
    }
    
    sort(friends.begin(), friends.end());
    
    int totalFactor = 0;
    int maxTotalFactor = 0;
    int left = 0;
    
    for(int i = 0; i < n; i++) {
        totalFactor += friends[i].second;
        
        while(friends[i].first - friends[left].first >= d) {
            totalFactor -= friends[left].second;
            left++;
        }
        
        maxTotalFactor = max(maxTotalFactor, totalFactor);
    }
    
    cout << maxTotalFactor << endl;
    
    return 0;
}