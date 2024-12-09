#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int left = m / 2;
    int right = (m + 1) / 2;
    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            cout << right << endl;
            right++;
            if(right > m) right = 1;
        } else {
            cout << left << endl;
            left--;
            if(left == 0) left = m;
        }
    }
    
    return 0;
}