#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> colors(n);
    
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (colors[i] == x) {
            count++;
        }
    }
    
    if (count >= 2) {
        // If there are at least 2 balls of color x, we can destroy all balls in the row
        cout << n << endl;
    } else {
        // If there is only 1 ball of color x, we can destroy all balls except the one of color x
        cout << n - 1 << endl;
    }
    
    return 0;
}