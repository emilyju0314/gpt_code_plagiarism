#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int heights[n];
    
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int minDiff = abs(heights[0] - heights[1]);
    int index1 = 1, index2 = 2;
    
    for(int i = 1; i < n; i++) {
        int diff = abs(heights[i] - heights[(i+1)%n]);
        if(diff < minDiff) {
            minDiff = diff;
            index1 = i+1;
            index2 = (i+2)%n + 1;
        }
    }
    
    cout << index1 << " " << index2 << endl;
    
    return 0;
}