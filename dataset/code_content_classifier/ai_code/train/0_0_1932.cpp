#include <iostream>
#include <vector>

using namespace std;

int main() {
    int d, n;
    cin >> d >> n;

    vector<int> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    int manual_changes = 0;
    for (int i = 0; i < n - 1; i++) {
        manual_changes += d - days[i];
    }

    cout << manual_changes << endl;

    return 0;
}