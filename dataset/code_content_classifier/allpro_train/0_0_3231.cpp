#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        int j = i + 2;
        while (j < n && points[j] - points[i] <= d) {
            count += (j - i - 1) * (j - i) / 2;
            j++;
        }
    }

    cout << count << endl;

    return 0;
}