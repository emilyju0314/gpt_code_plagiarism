#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperations(vector<int>& a, vector<int>& b) {
    int minA = *min_element(a.begin(), a.end());
    int maxB = *max_element(b.begin(), b.end());

    return max(0, maxB - minA);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << minOperations(a, b) << endl;

    return 0;
}