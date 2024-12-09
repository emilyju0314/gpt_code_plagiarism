#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    vector<int> slips(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> slips[i];
    }

    vector<int> jumps(n, -1);
    jumps[0] = 0;

    for(int i = 0; i < n; i++) {
        if(jumps[i] == -1) continue;
        for(int j = i + heights[i]; j < n; j++) {
            if(jumps[j] == -1 || jumps[j] > jumps[i] + 1) {
                jumps[j] = jumps[i] + 1;
            }
        }
        int slip_down = i + slips[i];
        if(slip_down < n) {
            if(jumps[slip_down] == -1 || jumps[slip_down] > jumps[i]) {
                jumps[slip_down] = jumps[i];
            }
        }
    }

    if(jumps[n-1] == -1) {
        cout << -1 << endl;
    } else {
        cout << jumps[n-1] << endl;
        int index = n - 1;
        vector<int> result(jumps[n-1] + 1);
        for(int i = jumps[n-1]; i >= 0; i--) {
            result[i] = index;
            index -= heights[index];
        }
        for(int i = 0; i <= jumps[n-1]; i++) {
            cout << result[i] << " ";
        }
    }

    return 0;
}