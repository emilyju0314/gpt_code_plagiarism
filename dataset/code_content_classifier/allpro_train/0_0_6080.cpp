#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> cubes(n);
        
        for(int i = 0; i < n; i++) {
            cin >> cubes[i];
        }
        
        bool sorted = true;
        int swaps = 0;
        
        for(int i = 1; i < n; i++) {
            if(cubes[i] < cubes[i-1]) {
                swaps += cubes[i-1] - cubes[i];
                cubes[i] = cubes[i-1];
            }
        }
        
        if(swaps <= (n*(n-1))/2 - 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}