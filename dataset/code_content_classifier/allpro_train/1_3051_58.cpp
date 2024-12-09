#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int line,n,i,j,q;
    cin>>line;
    while(line--)
    {
        cin>>n>>q>>str;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--,r--;
            bool flag=false;
            for(i=l-1; i>=0; i--)
            {
                if(str[i]==str[l])
                {
                    flag=true;
                    break;
                }
            }
            for(i=r+1; i<n; i++)
            {
                if(str[i]==str[r])
                {
                    flag=true;
                    break;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

