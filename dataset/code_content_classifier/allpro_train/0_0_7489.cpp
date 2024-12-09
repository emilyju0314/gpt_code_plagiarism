#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<m; i++) {
        int li, ri, xi;
        cin >> li >> ri >> xi;

        int pos = -1;
        for(int j=li-1; j<ri; j++) {
            if(a[j] != xi) {
                pos = j+1;
                break;
            }
        }

        cout << pos << endl;
    }

    return 0;
}