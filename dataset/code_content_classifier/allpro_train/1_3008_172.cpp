#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;cin>>s;
    int i=0,c=0,m=0,x=0;
    for(i=2;i<(s.size()-1);i++){
        if(s[i]=='C')
            c++;}
    for(m=0;m<s.size();m++){
        if(islower(s[m]))
            x++;}
    if(s[0]=='A'&&x==s.size()-2&&c==1)
        cout<<"AC";
    else
        cout<<"WA";
    return 0;
}
