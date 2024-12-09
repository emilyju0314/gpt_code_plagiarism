#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    set<pair<int, int>> visited;
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (visited.find(points[i]) == visited.end()) {
            visited.insert(points[i]);
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}