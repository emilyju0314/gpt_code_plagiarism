#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int n;
        cin >> n;
        
        vector<int> animals(n);
        unordered_map<int, int> color_map;
        
        int current_color = 1;
        
        for (int i = 0; i < n; i++) {
            cin >> animals[i];
            
            if (color_map[animals[i]] == 0) {
                color_map[animals[i]] = current_color;
                
                if (++current_color > 2) {
                    current_color = 1;
                }
            }
        }
        
        cout << 2 << endl;
        for (int i = 0; i < n; i++) {
            cout << color_map[animals[i]] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}