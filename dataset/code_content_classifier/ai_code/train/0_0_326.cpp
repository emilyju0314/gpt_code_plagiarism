#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int m;
    while (cin >> m) {
        if (m == 0) break;
        
        vector<pair<int, int>> constellation, photo;
        
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            constellation.push_back(make_pair(x, y));
        }
        
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            photo.push_back(make_pair(x, y));
        }
        
        int dx = photo[0].first - constellation[0].first;
        int dy = photo[0].second - constellation[0].second;
        
        cout << dx << " " << dy << endl;
    }
    
    return 0;
}