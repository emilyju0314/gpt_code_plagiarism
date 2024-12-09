#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    unordered_map<int, int> freqA, freqB;
    for(int i = 0; i < m; i++) {
        freqA[a[i]]++;
        freqB[b[i]]++;
    }

    vector<int> ans;
    for(int i = 0; i <= n - m; i++) {
        bool found = true;
        for(auto& it : freqB) {
            if(freqA[it.first] != it.second) {
                found = false;
                break;
            }
        }
        if(found) {
            ans.push_back(i + 1);
        }

        if(i + m < n) {
            freqA[a[i]]--;
            if(freqA[a[i]] == 0) {
                freqA.erase(a[i]);
            }
            freqA[a[i + m]]++;
        }
    }

    cout << ans.size() << endl;
    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}