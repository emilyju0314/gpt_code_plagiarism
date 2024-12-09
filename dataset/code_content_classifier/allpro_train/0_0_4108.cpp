#include <iostream>
#include <vector>

using namespace std;

struct Target {
    int xl, xr, yl, yr, z;
};

int main() {
    int n;
    cin >> n;
    
    vector<Target> targets(n);
    for (int i = 0; i < n; i++) {
        cin >> targets[i].xl >> targets[i].xr >> targets[i].yl >> targets[i].yr >> targets[i].z;
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        
        int hitTarget = 0;
        for (int j = 0; j < n; j++) {
            if (x >= targets[j].xl && x <= targets[j].xr && y >= targets[j].yl && y <= targets[j].yr && targets[j].z >= 0) {
                hitTarget = j + 1;
                targets[j].z = -1; // mark target as hit
                break;
            }
        }
        
        cout << hitTarget << endl;
    }
    
    return 0;
}