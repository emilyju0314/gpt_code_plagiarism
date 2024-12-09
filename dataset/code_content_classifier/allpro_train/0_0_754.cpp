#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    double ans = v[0];
    for (int i = 1; i < N; i++) {
        ans = (ans + v[i]) / 2.0;
    }

    cout << ans << endl;
    
    return 0;
}