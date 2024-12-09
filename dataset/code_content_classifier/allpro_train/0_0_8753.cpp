#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    int l = (1 << n);
    vector<int> a;

    if (n == 1 && x == 1) {
        cout << 0 << endl;
    } else {
        cout << l + 1 << endl;
        for (int i = 1; i < l; i++) {
            a.push_back(i);
        }
        a.push_back(x ^ l);
        
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}