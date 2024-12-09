#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> ans(n);
    int sum = 0;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        if (p[i] == curr + 1) {
            curr++;
        }
        sum += i - curr;
        ans[curr] = sum;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}