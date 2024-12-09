#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        int n; cin>>n>>s;
        if(s=="2020")cout<<"YES";
        else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[3]=='0') cout<<"YES";
        else if (s[n-1]=='0' && s[n-2]=='2' && s[n-3]=='0' && s[n-4]=='2') cout<<"YES";
        else if(s[0]=='2' && s[n-1]=='0' && s[n-2]=='2' && s[n-3]=='0') cout<<"YES";
        else if(s[0]=='2' && s[1]=='0' && s[n-1]=='0' && s[n-2]=='2') cout<<"YES";
        else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[n-1]=='0') cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}
