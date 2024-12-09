#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, P, Q;
    cin >> N >> P >> Q;

    vector<int> happiness(N);
    for (int i = 0; i < N; i++) {
        cin >> happiness[i];
    }

    long long maxHappiness = 0;
    long long currentHappiness = 0;

    for (int i = 0; i < N; i++) {
        long long cafeteriaHappiness = max(currentHappiness, 0LL) + happiness[i];
        long long selfCateringHappiness = max(currentHappiness + Q * P, 0LL) + happiness[i];

        maxHappiness += max(cafeteriaHappiness, selfCateringHappiness);
        currentHappiness = max(cafeteriaHappiness, selfCateringHappiness) - happiness[i];
    }

    cout << maxHappiness << endl;

    return 0;
}