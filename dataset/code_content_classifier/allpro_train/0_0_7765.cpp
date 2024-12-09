#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> tommy(n);
    vector<int> banban(m);

    for (int i = 0; i < n; i++) {
        cin >> tommy[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> banban[i];
    }

    sort(tommy.begin(), tommy.end());
    sort(banban.begin(), banban.end(), greater<int>());

    int maxBrightness = INT_MIN;

    for (int i = 0; i < n; i++) {
        int brightness = max(tommy[0] * banban[0], tommy[i] * banban[1]);
        maxBrightness = max(maxBrightness, brightness);
    }

    cout << maxBrightness << endl;

    return 0;
}