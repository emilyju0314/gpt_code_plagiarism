#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> balls(N);
    unordered_map<int, int> count;

    for (int i = 0; i < N; i++) {
        cin >> balls[i];
        count[balls[i]]++;
    }

    for (int k = 0; k < N; k++) {
        int total_ways = N - 1 - count[balls[k]] + 1;
        cout << total_ways << endl;
    }

    return 0;
}