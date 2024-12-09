#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> positions(n);
    for(int i = 0; i < n; i++) {
        cin >> positions[i];
    }
    
    long long totalDistance = 0;
    int lastCriminal = positions[0];
    for(int i = 1; i < n; i++) {
        totalDistance += max(abs(positions[i] - lastCriminal), 0);
        lastCriminal = positions[i];
    }
    
    cout << totalDistance << endl;
    
    return 0;
}