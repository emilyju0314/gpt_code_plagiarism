#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> red(N+1, 0);
    red[1] = 1;

    vector<int> balls(N+1, 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        balls[x]--;
        balls[y]++;

        if (red[x] > 0) {
            red[y]++;
            if (balls[x] == 0) red[x] = 0;
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (red[i] > 0) count++;
    }

    cout << count << endl;

    return 0;
}