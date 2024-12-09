#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_time = 0;

    int current_position = 0;
    for (int i = 0; i < n; i++) {
        total_time += min((current_position - i + n) % n, a[i]);
        current_position = (current_position - i + n + a[i]) % n;
    }

    cout << total_time << endl;

    return 0;
}