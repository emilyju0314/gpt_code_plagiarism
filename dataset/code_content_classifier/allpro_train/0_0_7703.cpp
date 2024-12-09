#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> count(N-W+1);

    for (int i = 1; i <= W; i++) {
        count[max(i, W-i+1)-1]++;
    }

    for (int i = 1; i <= N-W; i++) {
        count[i] += count[i-1];
    }

    for (int i = 0; i < N-W+1; i++) {
        cout << count[i] << " ";
    }
    cout << endl;

    return 0;
}