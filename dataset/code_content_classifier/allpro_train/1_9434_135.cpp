#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<numeric>
#include<map>
#include<limits>
using namespace std;

#define R(i,s,n) for(int i=s;i<n;i++)
#define D(i,n,s) for(int i=n-1;i>=s;i--)
typedef pair<int,int> P;
typedef unsigned long long ull;
typedef long long ll;

int n,m,t,p;

int main() {
  while(cin >> n >> m >> t >> p && !(!n && !m && !t && !p)){
    //初期化
    int d[t],c[t],x[p],y[p];
    R(i,0,t){
      cin >> d[i] >> c[i];
    }
    R(i,0,p){
      cin >> x[i] >> y[i];
    }
    vector< vector<int> > t1(32,vector<int>(32,0));
    R(i,0,m){
      R(j,0,n){
        t1[i][j] = 1;
      }
    }

    //折る
    //d=1左,d=2上
    R(oru,0,t){
      vector< vector<int> > t2(32,vector<int>(32,0));
      R(i,0,m){
        R(j,0,n){
          if(d[oru] == 1){
            if(c[oru]-j-1 >= 0) t2[i][j] += t1[i][c[oru]-j-1];
          }else{
            if(c[oru]-i-1 >= 0) t2[i][j] += t1[c[oru]-i-1][j];
          }
          if((d[oru]==1?j+c[oru]:i+c[oru]) >= 32)continue;
          t2[i][j] += t1[d[oru]==2?i+c[oru]:i][d[oru]==1?j+c[oru]:j];
        }
      }
      /*
      D(i,d[oru]==1?m:c[oru],0){
        D(j,d[oru]==2?n:c[oru],0){
          t2[d[oru]==1?m-i-1:c[oru]-i-1][d[oru]==2?n-j-1:c[oru]-j-1] += t1[i][j];
        }
      }*/
      t1 = t2;
    }
    /*
    R(i,0,32){
      R(j,0,32){
        cout << t1[i][j] << " ";
      }
      cout << endl;
    }
    */
    //穴
    R(ana,0,p){
      cout << t1[y[ana]][x[ana]] << endl;
    }
  }
  return 0;
}

