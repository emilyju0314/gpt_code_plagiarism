#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, N;
    cin >> L >> N;

    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    long long ans = 0;
    int left = 0, right = N - 1;
    long long dist_left = 0, dist_right = 0;

    while (left <= right) {
        long long dist_to_left = min(X[left], L - X[left]) + dist_left;
        long long dist_to_right = min(X[right], L - X[right]) + dist_right;

        if (dist_to_left < dist_to_right) {
            ans = max(ans, dist_to_right);
            dist_right += min(X[right], L - X[right]) * 2;
            right--;
        } else {
            ans = max(ans, dist_to_left);
            dist_left += min(X[left], L - X[left]) * 2;
            left++;
        }
    }

    cout << ans << endl;

    return 0;
}