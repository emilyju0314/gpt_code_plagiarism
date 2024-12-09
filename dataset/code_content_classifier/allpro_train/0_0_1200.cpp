#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> m(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }

    int minMoto = 0; // the minimum amount of Moto needed to make at least one of each doughnut
    for (int i = 0; i < N; i++) {
        minMoto += m[i];
    }

    int maxDoughnuts = X / minMoto;

    cout << maxDoughnuts << endl;

    return 0;
}