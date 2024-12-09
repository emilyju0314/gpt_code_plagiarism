#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> k(n), al(n), bl(n), ar(n), br(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i] >> al[i] >> bl[i] >> ar[i] >> br[i];
    }

    bool possible = true;
    vector<int> ans;
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (al[i] <= k[i] && k[i] <= bl[i]) {
            ans.push_back(0);
            left = max(left, k[i]);
            right = min(right, bl[i]);
        } else if (ar[i] <= k[i] && k[i] <= br[i]) {
            ans.push_back(1);
            right = max(right, k[i]);
            left = min(left, al[i]);
        } else {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
    } else {
        cout << "No\n";
    }

    return 0;
}