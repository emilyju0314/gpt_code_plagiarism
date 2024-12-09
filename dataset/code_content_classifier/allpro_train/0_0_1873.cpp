#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<pair<int, int>> targets(n);
    for(int i=0; i<n; i++) {
        cin >> targets[i].first >> targets[i].second;
    }

    cin >> m;

    vector<int> first_hit(n, -1);

    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;

        for(int j=0; j<n; j++) {
            int target_x = targets[j].first;
            int target_r = targets[j].second;

            if((x-target_x)*(x-target_x) + y*y <= target_r*target_r) {
                if(first_hit[j] == -1) {
                    first_hit[j] = i+1;
                }
            }
        }
    }

    int num_targets_hit = 0;
    for(int i=0; i<n; i++) {
        if(first_hit[i] != -1) {
            num_targets_hit++;
        }
    }

    cout << num_targets_hit << endl;
    for(int i=0; i<n; i++) {
        cout << first_hit[i] << " ";
    }

    return 0;
}  