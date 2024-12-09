#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ball {
    int color;
    int value;
};

bool compareBalls(Ball a, Ball b) {
    return a.value > b.value; // Sort in descending order of value
}

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    vector<int> limit(C);
    for (int i = 0; i < C; i++) {
        cin >> limit[i];
    }

    vector<Ball> balls(N);
    for (int i = 0; i < N; i++) {
        cin >> balls[i].color >> balls[i].value;
    }

    // Sort the balls by value in descending order
    sort(balls.begin(), balls.end(), compareBalls);

    long long totalValue = 0;
    vector<int> count(C + 1, 0);
    int selected = 0;

    for (int i = 0; i < N && selected < M; i++) {
        if (count[balls[i].color] < limit[balls[i].color - 1]) {
            count[balls[i].color]++;
            totalValue += balls[i].value;
            selected++;
        }
    }

    cout << totalValue << endl;

    return 0;
}