#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>
#include <functional>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <numeric>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vi vector<int>
#define INF (int)1e9
#define INFL 1e18
#define MOD 1e9+7
#define pb push_back
#define MP make_pair
typedef long long int ll;
typedef std::pair<int,int> P;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

using namespace std;
int main() {
    int t,d,l;
    while(cin>>t>>d>>l){
        if(!t&&!d&&!l)return 0;
        int ans=0;
        int x=0;
        rep(i,0,t){
            int p;
            cin>>p;
            if(p>=l)x=d;
            else x--;
            if(x>0)ans++;
        }
        cout<<max(0,ans-1)<<endl;
    }
    
    return 0;
}

