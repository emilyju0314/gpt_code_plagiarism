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

    int changes = 0;
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (a[current] > i) {
            current += i;
            changes++;
        } else {
            current -= i;
            changes++;
        }
    }

    cout << changes << endl;

    return 0;
}