#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> boxes(n);
    for(int i = 0; i < n; i++) {
        cin >> boxes[i];
    }
    
    if(n == 1 && boxes[0] == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    long long totalSeconds = 0;
    for(int i = 0; i < n; i++) {
        int curr = boxes[i];
        int next = boxes[(i+1)%n];
        if(curr % n == 0) {
            totalSeconds += curr/n;
        } else {
            int diff = n - (curr % n);
            totalSeconds += (curr + diff) / n;
            boxes[(i+1)%n] += diff;
        }
    }
    
    cout << totalSeconds << endl;

    return 0;
}