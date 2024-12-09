#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    string hats(n, '0');
    int blackCount = 0;
    
    for (int i = n-1; i >= 0; i--) {
        if (data[i] == 0) {
            if (blackCount % 2 == 1) {
                hats[i] = '1';
            }
        } else {
            if (data[i] % 2 == 1) {
                if (blackCount % 2 == 0) {
                    hats[i] = '1';
                    blackCount++;
                }
            } else {
                if (blackCount % 2 == 1) {
                    hats[i] = '1';
                }
            }
        }
    }
    
    cout << hats << endl;
    
    return 0;
}