#include <iostream>
#include <cstring>
using namespace std;

int T, W, H, A, B;

int countF(int x, int y) {
    if((x+1)%2 == 0 && (y+1)%3 == 0) return 1;
    return 0;
}

int main() {
    cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> W >> H >> A >> B;
        int ans = 0;
        for(int i=0; i<H*A; i++) {
            for(int j=0; j<W*B; j++) {
                ans += countF(i, j);
            }
        }
        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}
