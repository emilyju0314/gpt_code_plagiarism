#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isRectangle(int a, int b, int c) {
    vector<int> sides = {a, b, c};
    sort(sides.begin(), sides.end());
    return (sides[0] == sides[1] && sides[1] != sides[2]);
}

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    vector<int> straightBars(N), bentBars(M);
    for (int i = 0; i < N; i++) {
        cin >> straightBars[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> bentBars[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < Y; k++) {
                if (isRectangle(straightBars[i], bentBars[j], straightBars[k]) && k != i && k != j) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}