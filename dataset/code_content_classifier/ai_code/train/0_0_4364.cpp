#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> psychos(n);
    for (int i = 0; i < n; i++) {
        cin >> psychos[i];
    }

    int steps = 0;

    for (int i = 0; i < n; i++) {
        int j = i;

        while (j + 1 < n && psychos[j] > psychos[j + 1]) {
            j++;
        }

        if (j > i) {
            steps++;
        }

        i = j;
    }

    cout << steps << endl;

    return 0;
}