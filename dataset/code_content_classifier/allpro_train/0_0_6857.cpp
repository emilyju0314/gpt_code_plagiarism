#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        vector<int> operations;

        char target = '0';

        for(int i = n-1; i >= 0; i--) {
            if(a[i] != b[i]) {
                if(a[i] != target) {
                    operations.push_back(i+1);
                } else {
                    operations.push_back(1);
                    operations.push_back(i+1);
                    target = (target == '0') ? '1' : '0';
                }
            }
        }

        cout << operations.size() << " ";
        for(int op : operations) {
            cout << op << " ";
        }
        cout << endl;
    }

    return 0;
}