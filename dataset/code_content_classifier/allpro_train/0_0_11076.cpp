#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    int min_time = max(a[0]-1, n-a[m-1]);
    for (int i = 1; i < m; i++) {
        min_time = max(min_time, (a[i]-a[i-1] - 1) / 2);
    }

    cout << min_time << endl;

    return 0;
}