#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> vertical_spells, horizontal_points;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vertical_spells.push_back(x);
    }
    
    for (int i = 0; i < m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        horizontal_points.push_back(y);
    }
    
    sort(vertical_spells.begin(), vertical_spells.end());
    sort(horizontal_points.begin(), horizontal_points.end());
    
    int min_spells_to_remove = 0;
    
    if (vertical_spells.empty() || (horizontal_points.size() > 0 && horizontal_points[0] < vertical_spells[0])) {
        min_spells_to_remove++;
    }
    
    if (horizontal_points.empty() || (vertical_spells.size() > 0 && vertical_spells[0] < horizontal_points[0])) {
        min_spells_to_remove++;
    }
    
    cout << min_spells_to_remove << endl;
    
    return 0;
}