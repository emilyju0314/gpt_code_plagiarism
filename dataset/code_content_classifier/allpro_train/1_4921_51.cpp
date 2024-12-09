#include <iostream>

using namespace std;

void solve(int H,int W,int N) {
    int moji[H][W];
    int cnt[H+1][W+1];
    for(int i=0; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            cin >> moji[i][j]; // 0->south / 1->east
        }
    }

    // count visits for N-1 walk
    cnt[0][0]=N-1;
    for(int j=0; j<W-1; ++j) {
        cnt[0][j+1]=(cnt[0][j]+moji[0][j])/2;
    }
    for(int i=0; i<H-1; ++i) {
        cnt[i+1][0]=(cnt[i][0]+1-moji[i][0])/2;
    }
    for(int i=0; i<H-1; ++i) {
        for(int j=0; j<W-1; ++j) {
            cnt[i+1][j+1]=(cnt[i+1][j]+moji[i+1][j])/2+(cnt[i][j+1]+1-moji[i][j+1])/2;
        }
    }
    // calculate status after N-1 walk
    for(int i=0; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            moji[i][j]=(moji[i][j]+cnt[i][j])%2;
        }
    }
    // Nth walk
    int h=0, w=0;
    while(h<H && w<W) {
        if(moji[h][w]==0) ++h;
        else ++w;
    }
    cout << h+1 << " " << w+1 << endl;

    return;
}

int main() {
    int H,W,N;
    while(true) {
        cin >> H >> W >> N;
        if(H==0 && W==0 && N==0) break;
        solve(H,W,N);
    }
    return 0;
}
