#include <iostream>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    long long min_score = min(n, m);
    long long max_score = max(n, m);

    long long diff = max_score - min_score;

    if (diff <= 1) {
        cout << 0 << endl;
    } else {
        cout << diff - 1 << endl;
    }

    return 0;
}