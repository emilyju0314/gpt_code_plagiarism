#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> segments(n);
    for(int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
        if(segments[i].first > segments[i].second) {
            swap(segments[i].first, segments[i].second);
        }
    }
    
    sort(segments.begin(), segments.end(), cmp);
    
    int nails = 1;
    int current_nail = segments[0].second;
    vector<int> result = {current_nail};
    
    for(int i = 1; i < n; i++) {
        if(segments[i].first > current_nail) {
            nails++;
            current_nail = segments[i].second;
            result.push_back(current_nail);
        }
    }
    
    cout << nails << endl;
    for(int nail : result) {
        cout << nail << " ";
    }
    
    return 0;
}