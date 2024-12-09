#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n+3],mx=0,x,num;
        for(i=1;i<=n;i++)
            cin>>a[i];

        a[0]=-1;
        a[n+1]=100000000;

        sort(a,a+n+1);
        for(i=1;i<=n+1;i++)
        {
            if(a[i]!=a[i-1])
                {
                    num=i-x;
                    if(num>mx)
                        mx=num;
                    x=i;
                }

        }

        //cout<<mx;

        if(mx-n+mx>0)
            cout<<2*mx-n;
        else if(n%2)
            cout<<"1";
        else
            cout<<"0";


        cout<<endl;

    }

}

