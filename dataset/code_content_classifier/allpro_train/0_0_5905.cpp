#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int result = INT_MAX;

    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < m; j++) {
            temp = max(temp, a[i] & b[j]);
        }
        result = min(result, temp);
    }

    cout << result << endl;

    return 0;
}