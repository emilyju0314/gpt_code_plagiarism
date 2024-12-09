#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int N;
cin>>N;
vector<int> A(N+1);
vector<int> B(N);
for(int i=0;i<=N;i++)cin>>A[i];
for(int i=0;i<N;i++)cin>>B[i];
ll a=0;
 for(int i=0;i<N;i++){
    int x=min(A[i],B[i]);
    a+=x;
    B[i]-=x;
    x=min(A[i+1],B[i]);
    A[i+1]-=x;
    a+=x;
 }
 cout<<a<<endl;
return 0;
}