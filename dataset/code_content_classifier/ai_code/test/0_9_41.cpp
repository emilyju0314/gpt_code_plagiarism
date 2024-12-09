#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> colors(n*(n-1)/2, 1);
    
    if (k <= n/2) {
        cout << 2 << endl;
    } else {
        cout << n << endl;
    }

    for (int i = 0; i < n*(n-1)/2; i++) {
        cout << colors[i] << " ";
    }

    return 0;
}