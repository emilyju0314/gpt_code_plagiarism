#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] < s1 && x[i] < s2) {
            max_dist = max(max_dist, max(s1, s2) - x[i]);
            s1 = x[i];
        } else if (x[i] > s1 && x[i] > s2) {
            max_dist = max(max_dist, x[i] - min(s1, s2));
            s2 = x[i];
        }
    }

    cout << max_dist << endl;
    
    return 0;
}