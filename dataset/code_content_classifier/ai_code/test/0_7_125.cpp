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

    int current = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = current;
            current = current % n + 1;
        }
    }

    for (int num : a) {
        cout << num << " ";
    }

    return 0;
}