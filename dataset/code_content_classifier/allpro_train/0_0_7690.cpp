#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> alive(N, 1); // initialize all turkeys as alive
    vector<int> probability(N, 0); // initialize all probabilities as 0

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; // Adjust index to 0-based
        y--; // Adjust index to 0-based

        if (alive[x] && alive[y]) {
            probability[x]++;
            probability[y]++;
        } else if (alive[x] || alive[y]) {
            if (alive[x]) {
                probability[x]++;
            } else {
                probability[y]++;
            }
        }

        alive[x] = alive[y] = 0; // Set eaten turkeys as dead
    }

    int ans = 0;

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (probability[i-1] + probability[j-1] > 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}