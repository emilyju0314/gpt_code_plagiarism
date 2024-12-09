#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int total_ink = 0;
    for(int i = 0; i < m; i++) {
        int open_ink = a[i % n];
        int close_ink = b[i % n];
        total_ink += min(open_ink, close_ink);
    }

    cout << total_ink << endl;

    return 0;
}