#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> timeToDeliver(n, 0);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; // Adjust the station number for 0-based indexing
        
        if(a <= b) {
            timeToDeliver[a] += b - a;
        } else {
            timeToDeliver[a] += n - a + b;
        }
    }
    
    for(int startStation = 0; startStation < n; startStation++) {
        int totalTime = 0;
        for(int i = 0; i < n; i++) {
            int currStation = (startStation + i) % n;
            totalTime += timeToDeliver[currStation] + i;
        }
        cout << totalTime << " ";
    }
    
    return 0;
}