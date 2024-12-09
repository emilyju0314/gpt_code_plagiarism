#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, a;
    cin >> n >> k >> a;

    int m;
    cin >> m;

    vector<int> shots(m);
    for (int i = 0; i < m; i++) {
        cin >> shots[i];
    }

    // Find Bob's first move that reveals Alice's cheating
    int result = -1;
    for (int i = a; i <= m; i++) {
        int count = 0;
        for (int j = 0; j < k; j++) {
            if (shots[i-a] <= j * a || shots[i-a] > (j + 1) * a) {
                count++;
            }
        }
        if (count == k) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;
}