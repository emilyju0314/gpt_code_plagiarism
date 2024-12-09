#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n + 1); // 1-based indexing
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    // Find minimum k such that f(k)(x) is idempotent
    for(int k = 1; k <= n; k++) {
        vector<bool> visited(n + 1, false);
        int x = 1;
        for(int i = 0; i < k; i++) {
            if(visited[x]) {
                break; // The function is not idempotent
            }
            visited[x] = true;
            x = f[x]; // Apply function f to x
        }

        if(x == 1) {
            cout << k << endl;
            break;
        }
    }

    return 0;
}