#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    long long total_stones = 0;
    for (int i = 0; i < n; i++) {
        total_stones += stones[i];
    }

    long long target = (long long)n * (n + 1) / 2;

    if (total_stones % target == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}