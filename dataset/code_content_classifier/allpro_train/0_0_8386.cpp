#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    long long totalFatigue = 0;
    for (int i = 1; i < N; i++) {
        totalFatigue += min((long long)A * (X[i] - X[i - 1]), (long long)B);
    }

    cout << totalFatigue << endl;

    return 0;
}