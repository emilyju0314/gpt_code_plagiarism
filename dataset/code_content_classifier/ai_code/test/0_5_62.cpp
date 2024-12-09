#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int n, m, q;
set<pair<int, int>> locked;
unordered_map<int, int> count;

bool isFree(int x, int y) {
    return locked.find(make_pair(x, y)) == locked.end();
}

int numStaircases() {
    int count = 0;
    for (auto it = locked.begin(); it != locked.end(); ++it) {
        int x = it->first;
        int y = it->second;
        if (isFree(x-1, y) && isFree(x+1, y) && isFree(x, y-1) && isFree(x, y+1)) {
            count++;
        }
    }
    return count;
}

int main() {
    cin >> n >> m >> q;
    
    int result = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        
        if (locked.find(make_pair(x, y)) != locked.end()) {
            locked.erase(make_pair(x, y));
        } else {
            locked.insert(make_pair(x, y));
        }
        
        for (int j = x-1; j <= x+1; j++) {
            for (int k = y-1; k <= y+1; k++) {
                if (j < 1 || k < 1 || j > n || k > m) continue;
                count[numStaircases()]++;
            }
        }
        
        cout << count.rbegin()->first << endl;
    }

    return 0;
}