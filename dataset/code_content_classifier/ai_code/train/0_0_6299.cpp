#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> white_pos(N + 1);
    vector<int> black_pos(N + 1);
    int white_cost = 0;
    int black_cost = 0;

    for (int i = 1; i <= 2*N; i++) {
        char c;
        int a;
        cin >> c >> a;
        if (c == 'W') {
            white_pos[a] = i;
        } else {
            black_pos[a] = i;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            white_cost += white_pos[j] > white_pos[i];
            black_cost += black_pos[j] > black_pos[i];
        }
    }

    cout << min(white_cost, black_cost) + max(white_cost, black_cost) << endl;

    return 0;
}