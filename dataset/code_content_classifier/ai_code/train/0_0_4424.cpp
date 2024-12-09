#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int m, k, n, s;
    cin >> m >> k >> n >> s;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<int> b(s);
    unordered_map<int, int> required;
    for (int i = 0; i < s; i++) {
        cin >> b[i];
        required[b[i]]++;
    }

    int valid_workpiece_idx = -1;
    for (int i = 0; i < k; i++) {
        int idx = i;
        unordered_map<int, int> cnt;
        for (int j = i; j < m; j += k) {
            cnt[a[j]]++;
            if (j - idx + 1 >= k) {
                bool valid = true;
                for (auto& ele : required) {
                    if (cnt[ele.first] < ele.second) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    valid_workpiece_idx = idx;
                    break;
                }
                cnt[a[idx]]--;
                idx += k;
            }
        }
        if (valid_workpiece_idx != -1) {
            break;
        }
    }

    if (valid_workpiece_idx == -1) {
        cout << -1 << endl;
    } else {
        vector<int> removed;
        for (int i = 0; i < m; i++) {
            if (i < valid_workpiece_idx || i >= valid_workpiece_idx + k) {
                removed.push_back(i+1);
            }
        }
        cout << removed.size() << endl;
        for (int i : removed) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}