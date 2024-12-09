#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    map<int, int> freq;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        freq[nums[i]]++;
    }

    vector<int> selected;
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((nums[i] - nums[j]) % m == 0 && freq[nums[i]] > 0 && freq[nums[j]] > 0) {
                selected.push_back(nums[i]);
                selected.push_back(nums[j]);
                freq[nums[i]]--;
                freq[nums[j]]--;

                if (selected.size() == k) {
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        cout << "Yes" << endl;
        for (int i = 0; i < k; i++) {
            cout << selected[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}