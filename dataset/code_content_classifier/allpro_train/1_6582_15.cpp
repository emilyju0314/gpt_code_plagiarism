#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

int main()
{  
    int n,comm,key;
    string color;
    map<string,int>s;
    cin>>n;
    REP(i,n)
    {
        cin>>comm;
        if(comm==0)
        {
            cin>>color>>key;
            s[color]=key;
        }
        if(comm==1)
        {
            cin>>color;
            if(s.find(color)!=s.end())
            {
                cout<<s[color]<<endl;
            }else cout<<0<<endl;
        }
        if(comm==2)
        {
            cin>>color;
            s.erase(color);
        }
        if(comm==3)
        {
            string l,r;
            cin>>l>>r;
            decltype(s)::iterator it=s.lower_bound(l);
            decltype(s)::iterator end=s.upper_bound(r);
            while(it!=end)
            {
                cout<<it->first<<" "<<it->second<<endl;
                it++;
            }
        }
    }
}

