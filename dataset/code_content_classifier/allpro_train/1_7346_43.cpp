#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define N 1010
ll n;
unordered_set<ll> s;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
	ll p[3];
	for(int j=0;j<3;j++)cin>>p[j];
	sort(p,p+3);
	ll x=p[0]*N*N+p[1]*N+p[2];
	s.insert(x);
    }
    cout<<n-s.size()<<endl;
    return 0;
}

