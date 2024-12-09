#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int com,b,e;
        cin>>com>>b>>e;
        long long c[e-b-1];
        for(int i=0;i<e-b;i++)
        {
            c[i]=a[i+b];
        }
        int d=e-b;
        sort(c,c+d);
        if(com==0)
        {
            cout<<c[0]<<endl;
        }
        else
        {
            cout<<c[e-b-1]<<endl;
        }
    }
    return 0;
}

