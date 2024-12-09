#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> levels(n);
        for(int i = 0; i < n; i++) {
            cin >> levels[i];
        }
        
        sort(levels.begin(), levels.end());
        
        if(levels[0] == levels[n-1]) {
            cout << n << endl;
        } else {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(levels[i] == levels[n-1]) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }
    
    return 0;
}