#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> vertices(N);
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        vertices[i] = {A, B};
    }

    long long minWeight = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        int minA = vertices[i].first;
        int minB = vertices[(i + 1) % N].second;
        minWeight = min(minWeight, min(minA, minB));
    }

    cout << minWeight << endl;

    return 0;
}