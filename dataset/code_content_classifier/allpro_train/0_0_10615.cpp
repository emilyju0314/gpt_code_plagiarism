#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> t(n);
    int total_cells = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    for(int i = 0; i < n; i++) {
        total_cells += pow(2, i) * t[i];
    }
    
    cout << total_cells << endl;
    
    return 0;
}