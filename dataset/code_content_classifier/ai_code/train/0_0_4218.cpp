#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<long long> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    for (int i = 0; i < m; i++) {
        int room_number = b[i];
        int dormitory = lower_bound(prefix_sum.begin(), prefix_sum.end(), room_number) - prefix_sum.begin();
        int room_in_dormitory = room_number - (dormitory == 0 ? 0 : prefix_sum[dormitory - 1]);
        cout << dormitory + 1 << " " << room_in_dormitory << endl;
    }

    return 0;
}