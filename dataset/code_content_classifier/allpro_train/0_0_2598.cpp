#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    vector<int> pairs(N, 0);
    pairs[0] = 1;

    for (int i = 1; i < N; i++) {
        pairs[i] = pairs[p[i]] + 1;
    }

    for (int i = 0; i < N; i++) {
        cout << pairs[i] << endl;
    }

    return 0;
}