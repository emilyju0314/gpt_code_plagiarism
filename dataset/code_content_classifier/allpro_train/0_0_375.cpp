#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_area = 0;

    for(int i = l; i <= 100; i++) {
        int total_len = 0;

        for(int j = 0; j < n; j++) {
            total_len += (a[j] / i) * i;
        }

        max_area = max(max_area, total_len / i * i);
    }

    cout << max_area << endl;

    return 0;
}