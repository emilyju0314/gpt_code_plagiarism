#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    vector<int> ans(n);
    int days = 0;
    map<pair<int, int>, int> last_day;
    
    for (int i = 0; i < n; i++) {
        int minute = a[i].first;
        int index = a[i].second;
        
        int prev_day = last_day[{minute-d-1, 0}];
        int current_day = max(days, prev_day);
        
        ans[index] = current_day + 1;
        last_day[{minute, 0}] = current_day;
        last_day[{minute+d, 1}] = current_day;
        
        days = max(days, current_day + 1);
    }
    
    cout << days << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}