#include <iostream>
#include <vector>
#include <string>

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
        char cur = '0';
        for(int i = n-1; i >= 0; i--) {
            if(a[i] != b[i]) {
                if(a[i] != cur) {
                    operations.push_back(i+1);
                    cur = a[i];
                }
                operations.push_back(1);
                a[0] = (a[0] == '0' ? '1' : '0');
                for(int j = 0; j <= i; j++) {
                    a[j] = (a[j] == '0' ? '1' : '0');
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