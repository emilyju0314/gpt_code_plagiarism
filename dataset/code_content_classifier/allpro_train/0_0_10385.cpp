#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> health(n);
    for(int i=0; i<n; i++) {
        cin >> health[i];
    }

    vector<int> checkupItems(n);
    for(int i=0; i<n; i++) {
        checkupItems[i] = min(t / health[i], n-1);
    }

    for(int i=0; i<n; i++) {
        cout << checkupItems[i] + 1 << endl;
    }

    return 0;
}