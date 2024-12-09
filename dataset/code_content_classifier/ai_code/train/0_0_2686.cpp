#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> A(n+1, 0); // initializing sequence A with zeros
    
    while(q--) {
        int query;
        cin >> query;
        
        if(query == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            for(int i = s; i <= t; i++) {
                A[i] += x;
            }
        } else if(query == 1) {
            int i;
            cin >> i;
            cout << A[i] << endl;
        }
    }

    return 0;
}