#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> next(n);
        queue<int> idx;
        for(int i = 0; i < n; i++) {
            cin >> next[i];
            if(next[i] == -1) {
                idx.push(i);
            }
        }

        int remaining = n - idx.size();
        vector<int> permutation(n);
        for(int i = 0; i < n; i++) {
            if(next[i] != -1) {
                permutation[i] = next[i];
            }
            else {
                while(permutation[idx.front()] != 0) {
                    idx.pop();
                }

                permutation[idx.front()] = remaining--;
                idx.pop();
            }
        }

        bool valid = true;
        vector<bool> found(n + 1, false);
        for(int i = 0; i < n; i++) {
            if(permutation[i] == 0 || permutation[i] > n || found[permutation[i]]) {
                valid = false;
                break;
            }
            found[permutation[i]] = true;
        }

        if(valid) {
            for(int i = 0; i < n; i++) {
                cout << permutation[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}