#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> shortcuts(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> shortcuts[i];
    }

    vector<int> min_energy(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (shortcuts[i] == i) {
            min_energy[i] = min_energy[i - 1] + 1;
        } else {
            min_energy[i] = min_energy[shortcuts[i]] + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << min_energy[i] << " ";
    }
    cout << endl;

    return 0;
}