#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    vector<int> m;
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            vector<int> subseq(a.begin() + l, a.begin() + r + 1);
            sort(subseq.begin(), subseq.end());
            m.push_back(subseq[(r - l) / 2]);
        }
    }
    
    sort(m.begin(), m.end());
    
    cout << m[m.size() / 2] << endl;
    
    return 0;
}