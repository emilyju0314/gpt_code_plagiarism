#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int main () {
    int N, M, a, b;
    cin >> N >> a >> b >> M;

    map<int,int> A;

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        
        if (x == 0) {
            int Y, Z;
            if (A.find(y) != A.end()) Y = A[y];
            else Y = a + (y - 1) * b;
            if (A.find(z) != A.end()) Z = A[z];
            else Z = a + (z - 1) * b;
            
            A[y] = Z;
            A[z] = Y;
        } else {
            int Y, Z;
            if (A.find(z) != A.end()) Z = A[z];
            else Z = a + (z - 1) * b;
            
            A[y] = Z;
        }
    }

    int k;
    cin >> k;
    if (A.find(k) != A.end()) cout << A[k] << endl;
    else cout << a + (k - 1) * b << endl;
    
    return 0;
}