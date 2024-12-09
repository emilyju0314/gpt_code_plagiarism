#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    long long totalDamage = 0;
    vector<pair<int, int>> creatures(n);
    
    for(int i = 0; i < n; i++) {
        cin >> creatures[i].first >> creatures[i].second;
    }
    
    // Sort creatures by their damage value
    sort(creatures.begin(), creatures.end(), [](pair<int, int>& c1, pair<int, int>& c2) {
        return c1.second > c2.second;
    });
    
    for(int i = 0; i < n; i++) {
        if(a > 0 && creatures[i].first >= creatures[i].second) {
            totalDamage += creatures[i].first;
            a--;
        } else {
            totalDamage += creatures[i].second;
            if(b > 0) {
                creatures[i].first = creatures[i].second;
                b--;
            }
        }
    }
    
    cout << totalDamage << endl;
    
    return 0;
}