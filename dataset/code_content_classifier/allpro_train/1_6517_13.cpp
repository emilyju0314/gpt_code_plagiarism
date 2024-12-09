#include<bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
typedef long long ll;
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define v vector<ll>
#define debug(x) cerr<<#x<<" --> "<<x<<endl;
#define endl '\n'
const ll mxn=1e5+1;
const ll mod=1e9+7;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve()
{
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	f(i,0,s.length())
	{
		if(s[i]=='0')
		cnt++;
	}
	if(cnt==s.length())
	{
		cout<<s<<endl;
		return;
	}
	string temp=s;
	for(int j=0;j<min(m,n);j++)
	{
		int cnt=0;
		temp=s;
		if(s[0]=='0'&&s[1]=='1')
		{
			temp[0]='1';
			temp[1]='1';
		}
		if(s[s.length()-1]=='0'&&s[s.length()-2]=='1')
		{
			temp[s.length()-1]='1';
			temp[s.length()-2]='1';
		}
		f(i,1,s.length()-1)
		{
			if(s[i]=='0')
			{
				if((s[i-1]=='1'&&s[i+1]=='0')||(s[i-1]=='0'&&s[i+1]=='1'))
					temp[i]='1';
			}
		}
		f(k,0,temp.length())
			if(temp[k]=='1')
				cnt++;
		if(cnt==s.length())
			break;
		s=temp;
	}
	cout<<temp<<endl;
}

int main()
{
	fast;
	ll t;
	cin>>t;
	while(t--)
	   solve();
	return 0;
}




