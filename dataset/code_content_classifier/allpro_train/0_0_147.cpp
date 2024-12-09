#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 1e9;
    for(int i = 0; i < N; i++) {
        vector<int> removed(N, 0);
        int cnt = 0;
        int largest = -1;

        for(int j = 0; j < N; j++) {
            if(A[j] < A[i]) {
                removed[j] = 1;
                cnt++;
            }
            if(cnt == Q) {
                vector<int> mins;
                for(int k = 0; k < N; k++) {
                    if(removed[k] == 1) {
                        mins.push_back(A[k]);
                    }
                }
                if(mins.size() >= K) {
                    sort(mins.begin(), mins.end());
                    largest = max(largest, mins[K - 1]);
                }
                cnt--;
                removed[j - Q + 1] = 0;
            }
            if(largest != -1) {
                ans = min(ans, largest - A[i]);
            }
        }

    }

    cout << ans << endl;

    return 0;
}