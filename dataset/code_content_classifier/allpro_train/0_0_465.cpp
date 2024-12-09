#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    
    vector<pair<int, int>> coders(n);
    for (int i = 0; i < n; i++) {
        cin >> coders[i].first >> coders[i].second;
    }
    
    set<pair<int, int>> suspects;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int agreed = 0;
            for (int k = 0; k < n; k++) {
                if (coders[k].first == i + 1 || coders[k].first == j + 1 || 
                    coders[k].second == i + 1 || coders[k].second == j + 1) {
                    agreed++;
                }
            }
            
            if (agreed >= p) {
                suspects.insert({i + 1, j + 1});
            }
        }
    }
    
    cout << suspects.size() << endl;
    
    return 0;
}