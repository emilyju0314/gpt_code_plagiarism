#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;

    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    int criminalsCaught = 0;

    for (int i = 0; i < n; i++) {
        int distance = abs(i - a + 1);

        if (cities[i] == 1) {
            criminalsCaught++;
        }
    }

    cout << criminalsCaught << endl;

    return 0;
}