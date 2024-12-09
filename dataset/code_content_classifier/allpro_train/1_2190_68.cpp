#include<iostream>             
#include<vector>   
#include<bits/stdc++.h>
#define mod 1000000007
#define pi 3.14159265358979
#define  PRE(x,p) cout<<setprecision(x)<<p; 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define high INT_MAX
#define low INT_MIN
#define ll long long int

using namespace std;

pair<int,int>a[2002];
int pre1[2002];
int pre2[2002];
void solve() 
{ 
   int n,m,k,i,j,ans=0,l,r;
   
   cin>>n>>m>>k;
   
   for(i=1;i<=m;i++)
   cin>>a[i].f>>a[i].s;
   
   sort(a+1,a+m+1);
   int count1,count2;
   for(i=1;i<=n;i++)    //i is center 
   {
           vector<pair<int,int>>p1,p2;
           memset(pre1,0,sizeof(pre1));
           memset(pre2,0,sizeof(pre2));
           count1=count2=0;
           for(j=1;j<=m;j++)
           {
                 if(a[j].f+a[j].s<=2*i)
                 p1.pb(a[j]);
                 else
                 p2.pb(a[j]);
           }
           
           for(j=0;j<p1.size();j++)  //iterate on p1
           {
                pre1[p1[j].f]+=1;
                pre1[p1[j].s +1]-=1;
           }
           for(j=1;j<=n;j++) pre1[j]+=pre1[j-1];
           for(j=1;j<=n;j++) pre1[j]+=pre1[j-1];
           
      
          for(j=1;j<=n-k+1;j++)   //j is starting point
          {
              count1=max(count1,pre1[j+k-1]-pre1[j-1]);    
          }
            for(j=0;j<p2.size();j++)  //iterate on p2
           {
                pre2[p2[j].f]+=1;
                pre2[p2[j].s +1]-=1;
           }
           for(j=1;j<=n;j++) pre2[j]+=pre2[j-1];
           for(j=1;j<=n;j++) pre2[j]+=pre2[j-1];
       
          for(j=1;j<=n-k+1;j++)   //j is starting point
          {
              count2=max(count2, pre2[j+k-1]-pre2[j-1]);    
          }
          
           ans=max(ans,count1+count2);
           }
   
  
cout<<ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll t=1;
// cin>>t;
while(t--)
solve();
return 0;
}