#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }

    int ans = -1;
    for (int k = 2; k <= 100; k++) {
        int seconds = 0;
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            if (boxes[i] % k != 0 && boxes[i] != 0) {
                int target = min(boxes[i] % k, k - boxes[i] % k);
                if (i > 0 && boxes[i-1] % k == 0) {
                    seconds += target;
                    boxes[i-1] += target;
                    boxes[i] -= target;
                } else if (i < n-1 && boxes[i+1] % k == 0) {
                    seconds += target;
                    boxes[i+1] += target;
                    boxes[i] -= target;
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            if (ans == -1 || seconds < ans) {
                ans = seconds;
            }
        }
    }

    cout << ans << endl;

    return 0;
}