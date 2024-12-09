#include <iostream>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    
    int sum = 0;
    int max_mug = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        max_mug = max(max_mug, a);
    }
    
    if(sum - max_mug <= s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}