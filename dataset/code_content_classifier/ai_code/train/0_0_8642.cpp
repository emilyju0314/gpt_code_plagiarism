#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> computers(N);
    vector<int> sockets(N);

    for (int i = 0; i < N; i++) {
        cin >> computers[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> sockets[i];
    }

    sort(computers.begin(), computers.end());
    sort(sockets.begin(), sockets.end());

    long long total_length = 0;
    long long ways = 1;

    for (int i = 0; i < N; i++) {
        total_length += abs(computers[i] - sockets[i]);
    }

    cout << ways << endl;

    return 0;
}