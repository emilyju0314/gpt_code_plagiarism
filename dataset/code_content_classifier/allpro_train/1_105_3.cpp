#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef pair<int,int> p;

#define N 110
#define pi pair<int,int>
#define pb push_back

#define test \
        int t; \
        scanf("%d",&t);\
        while(t--)

ll llmax = numeric_limits<long long>::max();
ll llmin= numeric_limits<long long>::min();

int arr[N], grr[N];

int mat[1030][11];
char grid[60][60];
char gl[60][60];
char gn[60][60];

vector<int> v;
vector<string> srr;
vector<int> vy;
vector< vector<int> > g;
vector<pair<int,pair<int,int> > >pv;
map<ll,int>mp;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pqr;



int main()
{
    test
    {
        cout<<endl;
        int k,n,m;
        cin>>k>>n>>m;
        v.clear();
        for(int i=0; i<n; i++)
            cin>>arr[i];
        for(int i=0; i<m; i++)
            cin>>grr[i];
        int as = 0, gs =0;
        int tt = n+m;
        while(tt--)
        {

            if(arr[as]==0 && as<n)
            {
                k++;

                v.push_back(arr[as]);
                //cerr<<arr[as]<<endl;
                as++;
            }
            else if(arr[as]<=k && as<n)
            {

                v.push_back(arr[as]);
                //cerr<<arr[as]<<endl;
                as++;
            }
            if(grr[gs]==0 && gs<m)
            {
                k++;

                v.push_back(grr[gs]);
                //cerr<<grr[gs]<<endl;
                gs++;
            }
            else if(grr[gs]<=k && gs<m)
            {

                v.push_back(grr[gs]);
                //cerr<<grr[gs]<<endl;
                gs++;
            }

        }
        if(v.size()==n+m)
        {
            int sz=v.size();
            for(int i=0; i<sz; i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }

        else
        {
            cout<<"-1"<<endl;

        }


    }
}


