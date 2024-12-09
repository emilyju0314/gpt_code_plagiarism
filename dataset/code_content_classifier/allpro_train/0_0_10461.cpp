#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> sticks(N);
    for(int i = 0; i < N; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end(), greater<int>());

    int sum = 0;
    for(int i = 0; i < K; i++) {
        sum += sticks[i];
    }

    cout << sum << endl;

    return 0;
}