#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int max_occurrences = 0;
    int min_num = -1;

    for (auto& it : freq) {
        int num = it.first;
        int occurrences = it.second;
        int additional_ops = 0;

        if (occurrences <= k) {
            additional_ops = k - occurrences;
        } else {
            additional_ops = (occurrences - k % occurrences) % occurrences;
        }

        if (occurrences + additional_ops > max_occurrences) {
            max_occurrences = occurrences + additional_ops;
            min_num = num;
        } else if (occurrences + additional_ops == max_occurrences) {
            min_num = min(min_num, num);
        }
    }

    cout << max_occurrences << " " << min_num << endl;

    return 0;
}