#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int a, int b) {
    if (a==0 && b==0) {
        if (n == 2) {
            cout << "1 2" << endl;
        } else {
            cout << "-1" << endl;
        }
    } else if (a == 0 || b == 0 || a+b >= n || a+b < n-1) {
        cout << "-1" << endl;
    } else {
        vector<int> perm;
        for (int i = 1; i <= b+1; i++) {
            perm.push_back(i*2);
        }
        if (a > 0) {
            perm.insert(perm.begin()+a, 1);
        }
        int current = b+2;
        for (int i = 0; i < a+b; i++) {
            if (perm[i] == 0) {
                perm[i] = current++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (perm[i] == 0) {
                perm[i] = current++;
            }
        }
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }

    return 0;
}