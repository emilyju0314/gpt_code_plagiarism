#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPerformSequence(const vector<int>& a, const vector<int>& b, int target, int pos) {
    if (pos == a.size()) {
        return b.size() >= 1 && b.back() == target;
    }
    
    for (int i = 0; i < b.size(); i++) {
        for (int j = i; j < b.size(); j++) {
            vector<int> new_b = b;
            new_b.push_back(b[i] + b[j]);
            if (canPerformSequence(a, new_b, a[pos], pos+1)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int m = 1;
    while (true) {
        vector<int> b = {0};
        if (canPerformSequence(a, b, a[0], 1)) {
            cout << m << endl;
            return 0;
        }
        m++;
    }
    
    cout << -1 << endl;
    
    return 0;
}