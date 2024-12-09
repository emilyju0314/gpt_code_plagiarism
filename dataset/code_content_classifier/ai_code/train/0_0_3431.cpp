#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int N, L, M;
    cin >> N >> L >> M;

    vector<int> entryCost(N), exitCost(N), layerCost(N);

    for(int i = 0; i < N; i++) {
        cin >> entryCost[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> layerCost[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> exitCost[i];
    }

    vector<long long> count(N), temp(N);
    for(int i = 0; i < N; i++) {
        count[i] = entryCost[i];
    }

    for(int i = 1; i < L; i++) {
        for(int j = 0; j < N; j++) {
            temp[j] = 0;
            for(int k = 0; k < N; k++) {
                temp[j] += count[k] * layerCost[(j-k+N) % N];
                temp[j] %= M;
            }
        }
        count = temp;
    }

    long long result = 0;
    for(int i = 0; i < N; i++) {
        result += count[i] * exitCost[i];
        result %= M;
    }

    cout << result << endl;

    return 0;
}