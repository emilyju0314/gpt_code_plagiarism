#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> stairs(n);
    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }
    
    int m;
    cin >> m;
    
    int max_height = stairs[0];
    for (int i = 0; i < m; i++) {
        int w, h;
        cin >> w >> h;
        
        int current_height = max(max_height, stairs[w - 1]);
        cout << current_height << endl;
        
        max_height = current_height + h;
    }
    
    return 0;
}