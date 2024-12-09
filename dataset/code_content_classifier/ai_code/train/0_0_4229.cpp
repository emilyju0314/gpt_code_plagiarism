#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (a[a[i]-1] == i + 1) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}