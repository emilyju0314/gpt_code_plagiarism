#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++) {
        int A, X, B, Y, C;
        cin >> A >> X >> B >> Y >> C;
        
        int ans = 0;
        for(int j=1; j<=X; j++) {
            if(A*j % C == 0 && (Y*A + B*j) % C == 0) {
                ans = max(ans, j + Y);
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}