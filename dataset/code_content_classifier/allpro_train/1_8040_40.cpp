#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
pair<int,int> a[300010],c;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int main(){int n,r=0,i;cin>>n;for(i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);sort(a,a+n);long long s=0;for(i=0;i<n;i++){s+=a[i].x,c.x=a[i].y,c.y=a[i].x;q.push(c);while(!q.empty()){if(s<=q.size()*q.top().x)break;s-=q.top().y,q.pop();}if(r<q.size())r=q.size();}cout<<r<<endl;return 0;}