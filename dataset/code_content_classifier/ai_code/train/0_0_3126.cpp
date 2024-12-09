#include <iostream>
#include <vector>

using namespace std;

bool check_intersection(int x1, int y1, int x2, int y2) {
    return (x1 < x2 && y1 > y2);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> horizontal, vertical;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        
        if (x1 == x2) {
            vertical.push_back({x1, y1});
        } else {
            horizontal.push_back({y1, x1});
        }
    }

    int ans = 0;
    for (auto& h1 : horizontal) {
        for (auto& h2 : horizontal) {
            if (h1 < h2) {
                for (auto& v1 : vertical) {
                    for (auto& v2 : vertical) {
                        if (v1 < v2 && check_intersection(h1.second, h1.first, v1.first, v1.second) 
                            && check_intersection(h2.second, h2.first, v1.first, v1.second) 
                            && check_intersection(h1.second, h1.first, v2.first, v2.second) 
                            && check_intersection(h2.second, h2.first, v2.first, v2.second)) {
                                ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}