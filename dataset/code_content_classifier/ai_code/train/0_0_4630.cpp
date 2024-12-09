#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> friends;
    
    for(int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        friends.push_back(make_pair(w, h));
    }
    
    sort(friends.begin(), friends.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return max(a.first, a.second) < max(b.first, b.second);
    });
    
    long long total_width = 0, max_height = 0;
    
    for(int i = 0; i < n/2; i++) {
        total_width += max(friends[i].first, friends[i].second);
        max_height = max(max_height, min(friends[i].first, friends[i].second));
    }
    
    cout << max(total_width * max_height, total_width * max(max_height, friends[n/2].first + friends[n/2].second)) << endl;
    
    return 0;
}