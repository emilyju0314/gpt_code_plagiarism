#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    vector<int> ans;
    for (int i = N; i >= 1; i--) {
        int sum = 0;
        for (int j = i+i; j <= N; j += i) {
            sum += ans[j-1];
        }
        
        ans.push_back((sum % 2) != a[i-1]);
    }
    
    int M = 0;
    for (int i = 0; i < N; i++) {
        M += ans[i];
    }
    
    if (M == 0) {
        cout << "0" << endl;
    } else {
        cout << M << endl;
        for (int i = 0; i < N; i++) {
            if (ans[i] == 1) {
                cout << i+1 << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}