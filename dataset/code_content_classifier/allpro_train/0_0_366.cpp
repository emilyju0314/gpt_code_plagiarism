#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_moves = 0;
    for(int k = 1; k < n; k++) {
        total_moves += a[k-1];
        cout << total_moves << endl;
    }

    return 0;
}