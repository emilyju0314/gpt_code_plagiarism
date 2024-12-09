#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    vector<int> result(n, 0);
    for(int i = 0; i < n; i++) {
        int sum = 0, count = 0;
        for(int j = 0; j < n; j++) {
            if(j != i) {
                sum += t[j];
                if(sum <= m) {
                    count++;
                } else {
                    break;
                }
            }
        }
        result[i] = n - count - 1;
    }
    
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}