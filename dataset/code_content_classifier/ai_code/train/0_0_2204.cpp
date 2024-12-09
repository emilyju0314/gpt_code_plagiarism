#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int segments_x = 1;
    int segments_y = 1;

    for (int i = 1; i < n; i++) {
        if (x[i] != x[i - 1]) segments_x++;
        if (y[i] != y[i - 1]) segments_y++;
    }

    cout << min(segments_x, segments_y) << endl;

    return 0;
}