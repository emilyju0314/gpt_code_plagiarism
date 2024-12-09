#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> garland(n);
    for(int i = 0; i < n; i++) {
        cin >> garland[i];
    }
    
    // Count the number of removed bulbs
    int removed = 0;
    for(int i = 0; i < n; i++) {
        if(garland[i] == 0) removed++;
    }
    
    // Calculate the minimum complexity
    int complexity = 0;
    if(garland[0] == 0 || garland[n-1] == 0) {
        complexity = removed;
    } else {
        for(int i = 1; i < n; i++) {
            if(garland[i] != 0 && garland[i-1] % 2 != garland[i] % 2) {
                complexity++;
            }
        }
    }
    
    cout << complexity << endl;
    
    return 0;
}