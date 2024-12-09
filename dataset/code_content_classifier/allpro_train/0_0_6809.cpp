#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> diamonds(n);
    for(int i = 0; i < n; i++) {
        cin >> diamonds[i];
    }

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> diffs(n-1);
    for(int i = 0; i < n-1; i++) {
        diffs[i] = abs(diamonds[i] - diamonds[i+1]);
    }

    int maxLoot = 0;
    for(int i = 0; i < n-1; i++) {
        int moves = min(m, diffs[i]);
        if(k > moves) {
            maxLoot += min(diamonds[i], diamonds[i+1]);
            k -= moves;
        } else {
            maxLoot += min(diamonds[i], diamonds[i+1]) - (moves - k);
            break;
        }
    }

    cout << maxLoot << endl;
    
    return 0;
}