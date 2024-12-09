#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> logs(n);
    for(int i=0; i<n; i++) {
        cin >> logs[i];
    }
    
    sort(logs.begin(), logs.end());
    
    int max_area = 0;
    for(int i=0; i<n-1; i++) {
        int x = logs[i];
        int y = logs[i+1];
        
        max_area = max(max_area, min(x, y) * (n-i-1));
    }
    
    cout << max_area << endl;
    
    return 0;
}