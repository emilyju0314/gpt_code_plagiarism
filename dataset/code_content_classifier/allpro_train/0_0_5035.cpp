#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> scores(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> scores[i];
            sum += scores[i];
        }

        int max_score = min(sum + m, n * m);

        cout << max_score << endl;
    }

    return 0;
}