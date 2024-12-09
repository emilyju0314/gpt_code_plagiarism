#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long total_diversity = a[n-1] - a[0];
    int num_teams = 1;

    vector<int> team_assignments(n);
    for (int i = 0; i < n; i++) {
        team_assignments[i] = 1;
    }

    int min_diversity = total_diversity;
    for (int i = 3; i <= n/3; i++) {
        for (int j = i-1; j < n; j += i) {
            long long current_diversity = a[j] - a[j-i+1];
            if (min_diversity > (total_diversity - current_diversity) + i) {
                min_diversity = (total_diversity - current_diversity) + i;
                num_teams = i;
                for (int k = j-i+1; k <= j; k++) {
                    team_assignments[k] = i;
                }
            }
        }
    }

    cout << min_diversity << " " << num_teams << endl;
    for (int i = 0; i < n; i++) {
        cout << team_assignments[i] << " ";
    }
    cout << endl;

    return 0;
}