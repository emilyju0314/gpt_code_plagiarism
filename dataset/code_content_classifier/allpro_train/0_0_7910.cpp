#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> lines(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lines[i];
    }
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    int minMoves = abs(r1 - r2) + abs(c1 - c2);
    int minPos = c1;
    
    for (int i = r1; i != r2; i += (r1 < r2) ? 1 : -1) {
        minMoves = min(minMoves, abs(r1 - i) + minPos + c2);
        minPos = min(minPos, lines[i - 1] + 1);
    }
    
    cout << minMoves << endl;
    
    return 0;
}