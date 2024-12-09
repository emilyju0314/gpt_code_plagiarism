#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
  while(1){
    int H,W,R,C;
    scanf("%d %d %d %d",&H,&W,&R,&C);
    if(H==0)break;
    int goal[H+2][W+2];
    for(int i=0;i<=H+1;i++)for(int j=0;j<=W+1;j++){
      if(i*j==0||i==H+1||j==W+1)goal[i][j]=1;
      else goal[i][j]=0;
    }
    int hor[H+1][W];
    int ver[H][W+1];


    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++)scanf("%d",&hor[i][j]);
      for(int j=0;j<W+1;j++)scanf("%d",&ver[i][j]);
    }
    for(int i=0;i<W;i++)scanf("%d",&hor[H][i]);
    while(1){
      int flag=0;
    for(int i=1;i<=H;i++)for(int j=1;j<=W;j++){
      if(goal[i][j]==0&&goal[i-1][j]==1&&goal[i+1][j]==1&&hor[i-1][j-1]!=hor[i][j-1]){goal[i][j]=1;flag=1;}
      if(goal[i][j]==0&&goal[i][j-1]==1&&goal[i][j+1]==1&&ver[i-1][j-1]!=ver[i][j-1]){goal[i][j]=1;flag=1;}
    }
    for(int i=H;i>=1;i--)for(int j=W;j>=1;j--){
      if(goal[i][j]==0&&goal[i-1][j]==1&&goal[i+1][j]==1&&hor[i-1][j-1]!=hor[i][j-1]){goal[i][j]=1;flag=1;}
      if(goal[i][j]==0&&goal[i][j-1]==1&&goal[i][j+1]==1&&ver[i-1][j-1]!=ver[i][j-1]){goal[i][j]=1;flag=1;}
    }
    for(int i=1;i<=H;i++)for(int j=1;j<=W;j++){
      if(goal[i][j]==0&&goal[i-1][j]==1&&goal[i][j-1]==1&&hor[i-1][j-1]!=ver[i-1][j-1]){goal[i][j]=1;flag=1;}
    }
    for(int i=H;i>=1;i--)for(int j=1;j<=W;j++){
      if(goal[i][j]==0&&goal[i+1][j]==1&&goal[i][j-1]==1&&hor[i][j-1]!=ver[i-1][j-1]){goal[i][j]=1;flag=1;}
    }
    for(int i=1;i<=H;i++)for(int j=W;j>=1;j--){
      if(goal[i][j]==0&&goal[i-1][j]==1&&goal[i][j+1]==1&&hor[i-1][j-1]!=ver[i-1][j]){goal[i][j]=1;flag=1;}
    }
    for(int i=H;i>=1;i--)for(int j=W;j>=1;j--){
      if(goal[i][j]==0&&goal[i+1][j]==1&&goal[i][j+1]==1&&hor[i][j-1]!=ver[i-1][j]){goal[i][j]=1;flag=1;}
    }
    if(flag==0)break;
}
if(goal[R+1][C]==1&&hor[R][C-1]==0)printf("Yes\n");
else if(goal[R-1][C]==1&&hor[R-1][C-1]==0)printf("Yes\n");
else if(goal[R][C-1]==1&&ver[R-1][C-1]==0)printf("Yes\n");
else if(goal[R][C+1]==1&&ver[R-1][C]==0)printf("Yes\n");
else printf("No\n");
  }
  return 0;
}

