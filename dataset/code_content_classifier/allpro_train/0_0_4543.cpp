#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> swaps(n);
    for(int i = 0; i < n; i++) {
        cin >> swaps[i].first >> swaps[i].second;
    }
    
    vector<pair<int, int>> inversions;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(swaps[i].first > swaps[j].first) {
                inversions.push_back({swaps[i].first, swaps[j].first});
            }
            if(swaps[i].second > swaps[j].second) {
                inversions.push_back({swaps[i].second, swaps[j].second});
            }
        }
    }
    
    sort(inversions.begin(), inversions.end());
    inversions.erase(unique(inversions.begin(), inversions.end()), inversions.end());
    
    cout << inversions.size() << endl;
    
    return 0;
}