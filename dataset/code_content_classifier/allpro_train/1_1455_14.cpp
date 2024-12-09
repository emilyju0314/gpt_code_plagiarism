#include <iostream>
using namespace std;

int H,W,N,sx,sy;
int direction[4] = {};
string S,T;
int main(){
    cin >> H >> W >> N;
    cin >> sx >> sy;
    cin >> S >> T;
    for(int i=1;i<=N;i++){
        if(S[i-1]=='U') direction[0]++;
        if(S[i-1]=='L') direction[1]++;
        if(S[i-1]=='D') direction[2]++;
        if(S[i-1]=='R') direction[3]++;
        if(sx-direction[0]<=0 || H-sx-direction[2]+1<=0 
        || sy-direction[1]<=0 || W-sy-direction[3]+1<=0){
            cout << "NO" << endl;
            return 0;
        }
        if(T[i-1]=='U') direction[2] = max(direction[2]-1,-sx+1);
        if(T[i-1]=='L') direction[3] = max(direction[3]-1,-sy+1);
        if(T[i-1]=='D') direction[0] = max(direction[0]-1,sx-H);
        if(T[i-1]=='R') direction[1] = max(direction[1]-1,sy-W);
    }
    cout << "YES" << endl;
}