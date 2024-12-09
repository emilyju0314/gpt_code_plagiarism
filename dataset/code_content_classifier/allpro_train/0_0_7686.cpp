#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;

    long long max_capacity = max({A, B, C, D, E});
    long long min_time = (N + max_capacity - 1) / max_capacity;

    cout << min_time + 4 << endl;

    return 0;
}