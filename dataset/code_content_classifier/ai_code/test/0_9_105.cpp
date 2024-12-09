#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> dishes;
        vector<int> total_eat;

        for (int i = 0; i < n; i++) {
            int a, b, m;
            cin >> a >> b >> m;
            dishes.push_back({a, b});
            total_eat.push_back(m);
        }
        
        int min_variety = 0;
        
        for (int i = 0; i < n; i++) {
            min_variety += (total_eat[i] == 0 ? 1 : 0);
        }
        
        cout << min_variety << endl;
        
        for (int i = 0; i < n; i++) {
            int x, y;
            
            if (total_eat[i] == 0) {
                x = y = 0;
            } else {
                x = min(dishes[i].first, total_eat[i]);
                y = total_eat[i] - x;
            }
            
            cout << x << " " << y << endl;
        }
    }

    return 0;
}