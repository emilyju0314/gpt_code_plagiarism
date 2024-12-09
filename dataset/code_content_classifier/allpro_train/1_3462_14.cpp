#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  int t1,t2,r1,r2;
  cin>>t1>>t2>>r1>>r2;
  if(r1<0||r2<0){
    if(t1==t2) drop("Draw");
    if(t1>t2) drop("Bob");
    if(t1<t2) drop("Alice");
  }
  if(r1==r2) drop("Draw");
  if(r1<r2) drop("Bob");
  if(r1>r2) drop("Alice");
  return 0;
}

