#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> bottles(n);
    set<int> cannot_open;
    
    for (int i = 0; i < n; i++) {
        cin >> bottles[i].first >> bottles[i].second;
    }
    
    for (int i = 0; i < n; i++) {
        bool can_open = false;
        for (int j = 0; j < n; j++) {
            if (bottles[i].second == bottles[j].first) {
                can_open = true;
                break;
            }
        }
        if (!can_open) {
            cannot_open.insert(bottles[i].first);
        }
    }
    
    cout << cannot_open.size() << endl;
    
    return 0;
}