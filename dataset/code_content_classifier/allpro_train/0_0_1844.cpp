#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int x;
    cin >> x;
    
    vector<pair<pair<int,int>, pair<int,int>>> curses;
    
    for (int i = 0; i < n; i++) {
        int tl, tr, l, r;
        cin >> tl >> tr >> l >> r;
        curses.push_back({{tl, tr}, {l, r}});
    }
    
    sort(curses.begin(), curses.end());
    
    long long totalEnergy = 0;
    long long currentEnergy = 0;
    int currentPos = x;
    
    for (auto curse : curses) {
        int tl = curse.first.first;
        int tr = curse.first.second;
        int l = curse.second.first;
        int r = curse.second.second;
        
        currentEnergy += max(0, l - currentPos);
        totalEnergy += currentEnergy;
        
        currentEnergy -= max(0, r - max(currentPos, tl));
        currentPos = max(currentPos, tr);
    }
    
    cout << totalEnergy << endl;
    
    return 0;
}