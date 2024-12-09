#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> diamonds(n);
    for (int i = 0; i < n; i++) {
        cin >> diamonds[i];
    }

    int looted = 0;
    int moves = min(m, k-1);

    for (int i = 0; i < n-1; i++) {
        int diff = diamonds[i] + diamonds[i+1];
        if (diff > looted) {
            looted = diff;
        }
    }

    cout << looted << endl;

    return 0;
}