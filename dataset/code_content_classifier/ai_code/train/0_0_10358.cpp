#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p[p[i]-1] != i+1) {
            cnt++;
        }
    }

    int min_not_present = (cnt + 1) / 2;
    int max_not_present = min(cnt, 2 * k);

    cout << min_not_present << " " << max_not_present << endl;

    return 0;
}