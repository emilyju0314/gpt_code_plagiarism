#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> beads(n);
    int total = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> beads[i];
        total += beads[i];
    }
    
    int max_cuts = 0;
    char current_color = 'a';
    
    for(int i = 0; i < n; i++) {
        int count = min(beads[i], beads[(i+1)%n]);
        
        max_cuts += count;
        
        for(int j = 0; j < count; j++) {
            cout << current_color;
        }
        
        current_color++;
    }
    
    cout << endl;
    
    cout << max_cuts << endl;
    
    return 0;
}