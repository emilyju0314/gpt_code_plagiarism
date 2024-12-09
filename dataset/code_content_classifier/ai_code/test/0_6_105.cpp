#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<pair<int, int>, int>> dishes(n);
        
        for(int i = 0; i < n; i++) {
            int a, b, m;
            cin >> a >> b >> m;
            dishes[i] = make_pair(make_pair(a, b), m);
        }
        
        sort(dishes.begin(), dishes.end());
        
        int totalVariety = 0;
        vector<pair<int, int>> output;
        
        for(int i = 0; i < n; i++) {
            if(i == 0 || dishes[i].first != dishes[i-1].first) {
                output.push_back(make_pair(0, dishes[i].second));
            } else {
                output.push_back(make_pair(0, 0));
                totalVariety++;
            }
        }
        
        cout << totalVariety << "\n";
        
        for(auto dish : output) {
            cout << dish.first << " " << dish.second << "\n";
        }
    }
    
    return 0;
}