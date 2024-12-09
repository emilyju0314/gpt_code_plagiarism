#include<bits/stdc++.h>
using namespace std;

char f(char a, char b, char k)
{
    if((k=='o'&&b=='S')||(k=='x'&&b=='W'))return a;
    else
    {
        if(a=='S')return 'W';
        else return 'S';
    }
}

int main()
{
    int n;string s;
    cin>>n>>s;
    string d[4]={"SS","SW","WS","WW"};
    for(int i=0;i<4;i++)
    {
        string ans=d[i];
        for(int i=0;i<n-2;i++)
        {
            ans+=f(ans[i],ans[i+1],s[i+1]);
        }
        if(f(ans[n-2],ans[n-1],s[n-1])!=ans[0])continue;
        if(f(ans[n-1],ans[0],s[0])!=ans[1])continue;
        cout<<ans<<endl;
        return 0;
    }
    cout<<-1<<endl;

}
