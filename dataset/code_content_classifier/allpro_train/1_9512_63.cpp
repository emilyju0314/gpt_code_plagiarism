#include<bits/stdc++.h>
using namespace std;
string s;
int n,d,c;
int main()
{
    cin>>n>>s;
    for(int i=0; s[i]; i++)
    {
        if(s[i]=='(')c++;
        else c--;
        d=min(d,c);
    }
    for(int i=0; i<-d; i++)cout<<"(";
    cout<<s;
    for(int i=0; i<c-d; i++)cout<<")";
    return 0;
}
