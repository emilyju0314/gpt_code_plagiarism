#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, pair<int, int>>> horizontal_segments;
    vector<pair<int, pair<int, int>>> vertical_segments;
    
    for(int i = 0; i < n; i++) {
        int y, lx, rx;
        cin >> y >> lx >> rx;
        horizontal_segments.push_back({y, {lx, rx}});
    }
    
    for(int i = 0; i < m; i++) {
        int x, ly, ry;
        cin >> x >> ly >> ry;
        vertical_segments.push_back({x, {ly, ry}});
    }
    
    sort(horizontal_segments.begin(), horizontal_segments.end());
    sort(vertical_segments.begin(), vertical_segments.end());
    
    set<int> x_coords;
    for(auto segment : horizontal_segments) {
        x_coords.insert(segment.second.first);
        x_coords.insert(segment.second.second);
    }
    
    for(auto segment : vertical_segments) {
        x_coords.insert(segment.first);
    }
    
    int count = 1;
    for(int x : x_coords) {
        for(auto segment : horizontal_segments) {
            if(x >= segment.second.first && x < segment.second.second) {
                count++;
                break;
            }
        }
        for(auto segment : vertical_segments) {
            if(x >= segment.second.first && x < segment.second.second) {
                count++;
                break;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}