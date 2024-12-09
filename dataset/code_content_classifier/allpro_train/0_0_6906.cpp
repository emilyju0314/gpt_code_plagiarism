#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> balls(N);
    for (int i = 0; i < N; i++) {
        cin >> balls[i];
    }

    map<int, int> last_seen;
    vector<int> changes_occurred(N, 0);

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;

        changes_occurred[X-1] = 1;
        last_seen[X] = i + 1;

        if (balls[X-1] == Y) {
            cout << 0 << endl;
        } else {
            int min_changes = 0;
            for (int j = 1; j <= N; j++) {
                if (changes_occurred[j-1] && last_seen[balls[j-1]] >= last_seen[Y]) {
                    min_changes++;
                }
            }
            cout << min_changes << endl;
        }

        balls[X-1] = Y;
    }

    return 0;
}