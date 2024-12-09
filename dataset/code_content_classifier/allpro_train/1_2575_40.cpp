#include <bits/stdc++.h>
using namespace std;
int main(){long long a,b,c; cin>>a>>b>>c;long long d=c-a-b;long long e=4*a*b;cout<<(d<0||d*d<=e? "No":"Yes")<<endl;}