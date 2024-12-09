#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
vector<long long int>arr(n);
long long int all(0);
for(int i=0; i<n; ++i)
{
cin>>arr[i];
all+=arr[i];
}
long long int sum(0),mn(1000000000000000000LL);
for(int i=0; i<n-1; ++i)
{
sum+=arr[i];
mn=min(mn,abs(sum-(all-sum)));
}
cout<<mn;
}