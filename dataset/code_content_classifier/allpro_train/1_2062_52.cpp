#include<bits/stdc++.h>
using namespace std;
int main()
{

string s,ss,x;
int a,b,i,j,l,k;
vector<int>v;
map<int,int>m;

cin>>a>>b;
for(i=1;i<=b;i++)
{
cin>>l>>k;m[l]++;m[k]++;
}
for(i=1;i<=a;i++)
cout<<m[i]<<endl;
}