#include <iostream>
using namespace std;

int main() {
    int W, H, K;
    cin >> W >> H >> K;

    long long ans = 0;
    for(int x1=1; x1<W; x1++) {
        for(int y1=1; y1<H; y1++) {
            for(int x2=W-1; x2>0; x2--) {
                for(int y2=1; y2<H; y2++) {
                    int inside = (x2-x1-1)*(y2-y1-1);
                    if(inside <= K) {
                        ans += (W-x2)*(y1+H-y2);
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}