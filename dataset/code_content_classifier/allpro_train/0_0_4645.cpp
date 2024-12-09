#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &a, vector<int> &b, vector<int> &c) {
    for (int i = 0; i < a.size(); i++) {
        int sum = 0;
        for (int j = 0; j < a.size(); j++) {
            sum += a[j] * b[(i+j)%a.size()];
        }
        if (sum != c[i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n), c(n), a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    vector<vector<int>> res;
    
    for (int shift = 0; shift < n; shift++) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = c[(i+shift)%n];
        }
        if (check(temp, b, c)) {
            res.push_back(temp);
        }
    }
    
    cout << res.size() << endl;
    
    sort(res.begin(), res.end());
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}