#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    int w, h;
    while(cin>>w>>h && h|w){
        static int dp[111][111][4];
        for(int i=0;i<111;i++)
            for(int j=0;j<111;j++)
                for(int k=0;k<4;k++)dp[i][j][k]=0;
        for(int i=0;i<h;i++)dp[i][0][0]=1;
        for(int i=0;i<w;i++)dp[0][i][2]=1;
        for(int i=1;i<h;i++){
            for(int j=1; j<w; j++){
                if(i-1>=0)dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][1];
                if(i-1>=0)dp[i][j][1]+=dp[i-1][j][2];
                if(j-1>=0)dp[i][j][2]+=dp[i][j-1][2]+dp[i][j-1][3];
                if(j-1>=0)dp[i][j][3]+=dp[i][j-1][0];
                for(int k=0; k<4; k++)dp[i][j][k]%=100000;
            }
        }

        int ans=0;
        for(int i=0; i<4; i++) ans+=dp[h-1][w-1][i];
        cout << ans%100000 << endl;
    }
}