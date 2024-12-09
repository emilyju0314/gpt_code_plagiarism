// author::Rudra //
#include<iomanip>
#include<queue>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#define int long long
#define mod 1000000007
#define cnst 1000005
#define pb push_back
#define mk make_pair
using namespace std;
vector<int>p(1000005);
int bin_pow(int x,int y,int m)
{
    int ans;
    if(y==0) return 1;
    ans=bin_pow(x, y/2,m);
    if(y%2==0) return ((ans*ans)%m);
    return (x*((ans*ans)%m))%m;
}

int mult(int a,int b,int m)
{
    int ans= ((a%m)*(b%m))%m;
    return ans;
}
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
bool cmp(int a,int b)
{
    return a<b;
}

// Keep calm and Keep coding //

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        if((a==0||b==1)&&k!=0)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(a!=0&&!(k<=a+b-2))
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        if(k==0)
        {
            for(int i=0;i<a+b;i++)
            {
                if(i<b) cout<<1;
                else cout<<0;
            }
            cout<<endl;
            for(int i=0;i<a+b;i++)
            {
                if(i<b) cout<<1;
                else cout<<0;
            }
            cout<<endl;
            continue;
        }
        
        if(a<b)
        {
            for(int i=0;i<a+b;i++)
            {
                if(i<b) cout<<1;
                else cout<<0;
            }
            cout<<endl;
            if(k<=a)
            {
                for(int i=0;i<a+b;i++)
                {
                    if((i<b-1)||(i==b+k-1)) cout<<1;
                    else cout<<0;
                }
                cout<<endl;
            }
            else
            {
                for(int i=0;i<a+b;i++)
                {
                    if(((i<b)&&(i!=a+b-1-k))||(i==a+b-1)) cout<<1;
                    else cout<<0;
                }
                cout<<endl;
            }
        }
        else
        {
            int x=a+b-2-k;
            for(int i=0;i<a+b;i++)
            {
                if(i<b) cout<<1;
                else cout<<0;
            }
            cout<<endl;
            for(int i=0;i<a+b;i++)
            {
                if((i<b&&i!=1)||(i==a+b-1-x)) cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }
    }
}

























