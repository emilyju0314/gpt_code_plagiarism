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

    vector<int> violations(n - 1, 0);

    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            int parent = (i - 2) / k + 1;
            if (a[i] < a[parent]) {
                violations[k-1]++;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << violations[i] << " ";
    }

    return 0;
}