#include<bits/stdc++.h>
using namespace std ;
#define int long long  

int32_t main()
{
    int t; 
    cin>>t; 
    while(t--)
    {
        int n; 
        cin>>n ; 
        vector<int>v(2*n); 
        for (int i = 0; i < 2*n; ++i)
        {
            cin>>v[i]; 
        }

        sort(v.begin(), v.end()); 
        std::vector<int> res;

        int i=0 ; 
        int j=2*n-1; 
        while(i<j)
        {
            res.push_back(v[i]); 
            res.push_back(v[j]); 
            i++; 
            j--; 
        }

        for (int i = 0; i < res.size(); ++i)
        {
            cout<<res[i]<<" "; 
        }
        cout<<endl ;
    }

}
