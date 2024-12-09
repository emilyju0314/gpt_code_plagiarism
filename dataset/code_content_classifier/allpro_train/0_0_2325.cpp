#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    
    vector<int> ans;
    ans.push_back(x);
    
    for (int i = 1; i <= 2*N-1; i++) {
        if (i != x) {
            ans.push_back(i);
        }
    }
    
    if (x == 1 || x == 2*N-1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
    
    return 0;
}