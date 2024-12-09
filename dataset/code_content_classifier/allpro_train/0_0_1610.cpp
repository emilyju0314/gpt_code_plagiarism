#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> qualities(n);
    for(int i = 0; i < n; i++) {
        cin >> qualities[i];
    }

    vector<long long> guesses(m);
    for(int i = 0; i < m; i++) {
        cin >> guesses[i];
    }

    vector<int> prefix_sum(n+1);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + qualities[i-1];
    }

    int min_removed = 0;
    for(int i = 0; i < m; i++) {
        int mood = guesses[i];
        int max_pos = 0;
        for(int j = 1; j <= n; j++) {
            if(prefix_sum[j] <= mood) {
                max_pos = j;
            }
        }
        min_removed = max(min_removed, n - max_pos);
        cout << n - max_pos << endl;
    }

    return 0;
}