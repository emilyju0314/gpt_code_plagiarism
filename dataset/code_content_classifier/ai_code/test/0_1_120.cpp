#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        int l, r;
        cin >> l >> r;

        if((r & (r - 1)) >= l){
            cout << r - 1 << endl;
        } else {
            cout << r - 2 << endl;
        }
    }

    return 0;
}