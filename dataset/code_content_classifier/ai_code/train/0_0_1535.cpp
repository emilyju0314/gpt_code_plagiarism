#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int k;
    cin >> k;

    unordered_map<long long, pair<int, int>> sumToIndex;

    for(int i = 1; i <= k; i++) {
        int n;
        cin >> n;

        vector<int> sequence(n);
        long long sum = 0;
        for(int j = 0; j < n; j++) {
            cin >> sequence[j];
            sum += sequence[j];
        }

        for(int j = 0; j < n; j++) {
            long long newSum = sum - sequence[j];
            if(sumToIndex.find(newSum) != sumToIndex.end()) {
                pair<int, int> otherSeq = sumToIndex[newSum];
                if(otherSeq.first != i) {
                    cout << "YES" << endl;
                    cout << otherSeq.first << " " << otherSeq.second + 1 << endl;
                    cout << i << " " << j + 1 << endl;
                    return 0;
                }
            } else {
                sumToIndex[newSum] = make_pair(i, j);
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}