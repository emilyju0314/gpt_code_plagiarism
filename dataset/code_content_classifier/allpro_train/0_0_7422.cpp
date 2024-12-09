#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }

    int distance = 0;
    for (int i = 0; i < N; i++) {
        if ((P[i] != i) || (Q[i] != i)) {
            distance++;
        }
    }

    cout << distance << endl;

    return 0;
}