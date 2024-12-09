//Jai Shri Ram
//Jai Shri Krishna

#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi ;
typedef map<int,int> mii ;
typedef pair<int,int> pii ;
#define pb push_back
#define all(V) V.begin(),V.end()
#define uniq(v)       (v).erase(unique(all(v)),(v).end())
#define distinct(v)   distance(v.begin(), unique(all(v)))     //first sort then use
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define fill(baxq,I)   (memset(baxq,I,sizeof(baxq)))
#define sz(x) (int)((x).size())
#define endl  "\n"


const int32_t mod=1e9+7;
const long long inf=1e18;
const int N = 1e5+5;

void testCases()
   {
      int a,b;
      cin>>a>>b;

      if(a==b)cout<<0<<" "<<0<<endl;
      else
      {  
         int x= abs(a-b);
         int y=max(a,b);
         int q=min(a,b);
         int h=x*((y+x-1)/x) - y;
         int k= q- x*((q)/x);
         cout<<abs(a-b)<<" "<<min(h,k)<<endl;
      }


   }

int32_t main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);


    int tcs=1;
    cin>>tcs;
    while(tcs--)
       {    
            testCases() ;
       }

}