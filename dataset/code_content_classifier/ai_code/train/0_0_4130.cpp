#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, A, B, C, T;
    cin >> n >> A >> B >> C >> T;

    vector<int> ti(n);
    for(int i = 0; i < n; ++i) {
        cin >> ti[i];
    }

    int total_score = n * A;
    for(int i = 0; i < n; ++i) {
        total_score += max(0, A - B * (T - ti[i]));
    }

    int max_score = max(total_score, (n * A) + C * n * (T - 1));

    cout << max_score << endl;

    return 0;
}