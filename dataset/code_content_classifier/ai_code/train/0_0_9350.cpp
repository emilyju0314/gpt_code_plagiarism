#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tank {
    int x1, y1, x2, y2;
};

bool comp(Tank t1, Tank t2) {
    if(t1.x1 != t2.x1) {
        return t1.x1 < t2.x1;
    }
    return t1.y1 < t2.y1;
}

int main() {
    int n;
    cin >> n;
    
    vector<Tank> tanks(n);
    for(int i=0; i<n; i++) {
        cin >> tanks[i].x1 >> tanks[i].y1 >> tanks[i].x2 >> tanks[i].y2;
    }
    
    sort(tanks.begin(), tanks.end(), comp);
    
    int shots = 0;
    int maxY = -1e9;
    
    for(int i=0; i<n; i++) {
        if(tanks[i].y1 > maxY) {
            shots++;
            maxY = tanks[i].y2;
        } else {
            maxY = max(maxY, tanks[i].y2);
        }
    }
    
    cout << shots << endl;
    
    return 0;
}