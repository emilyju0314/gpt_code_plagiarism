#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K;
    cin >> K;
    
    vector<int> a(K);
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }
    
    vector<int> P;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < a[i]; j++) {
            P.push_back(i + 1);
        }
    }
    
    vector<int> count(K);
    for (int i = 0; i < P.size(); i++) {
        count[P[i] - 1]++;
        if (i >= K - 1) {
            vector<int> subsequence(count.begin(), count.end());
            sort(subsequence.begin(), subsequence.end());
            bool valid = true;
            for (int j = 0; j < K; j++) {
                if (subsequence[j] != j + 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                for (int j = 0; j < P.size(); j++) {
                    cout << P[j] << " ";
                }
                cout << endl;
                return 0;
            }
            count[P[i - K + 1] - 1]--;
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}