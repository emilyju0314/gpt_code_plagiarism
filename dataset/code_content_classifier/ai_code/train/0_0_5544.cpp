#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canArrangeRectangles(vector<pair<int, int>>& rectangles) {
    sort(rectangles.begin(), rectangles.end());
    int currHeight = rectangles[0].second;
    
    for(int i = 1; i < rectangles.size(); i++) {
        if(rectangles[i].first <= currHeight) {
            currHeight = max(rectangles[i].first, rectangles[i].second);
        } else {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> rectangles(n);
    
    for(int i = 0; i < n; i++) {
        cin >> rectangles[i].first >> rectangles[i].second;
    }
    
    if(canArrangeRectangles(rectangles)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}