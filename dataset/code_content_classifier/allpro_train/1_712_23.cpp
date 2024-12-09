#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   ll t;
   cin>>t;

   ll seive[100001],i,j;
   vector <ll> v;
   for(i=0;i<=100000;i++)
    seive[i]=0;

   seive[2]=1;
   for(i=3;i<=100000;i+=2)
     seive[i]=1;

   for(i=3;i<=100000;i+=2)
   {
       if(seive[i]==1)
       for(j=i*i;j<=100000;j+=i)
         seive[j]=0;
    }
    v.push_back(2);
   for(i=3;i<=100000;i+=2)
   {
       if(seive[i]==1)
        v.push_back(i);
   }
   while(t--)
   {
       ll d,a,ans=0,f;
       cin>>d;

       for(i=0;i<v.size();i++)
       {
           a=v[i]-1;
           if(a>=d)
           {
               f=i;
               break;
           }
       }
       for(i=f;i<v.size();i++)
       {
           a=v[i]-v[f];
           if(a>=d)
           {
               ans=v[i]*v[f];
               break;
           }
       }

       cout<<ans<<endl;
   }
   return 0;
}
