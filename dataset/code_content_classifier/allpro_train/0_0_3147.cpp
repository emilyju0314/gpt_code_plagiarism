#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < m; i++) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int v, x;
            cin >> v >> x;
            arr[v-1] = x;
        } else if(type == 2) {
            int y;
            cin >> y;
            for(int j = 0; j < n; j++) {
                arr[j] += y;
            }
        } else if(type == 3) {
            int q;
            cin >> q;
            cout << arr[q-1] << endl;
        }
    }
    
    return 0;
}