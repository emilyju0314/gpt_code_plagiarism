#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <numeric>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define itrep(i,x) for(auto i=(x).begin(); i!=(x).end();i++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vec vector
#define INF (int)1e9
#define INFL 1e18
#define MOD 1000000007
#define pb push_back
#define MP make_pair
#define PI 3.1415926535
#define fcout cout<<fixed<<setprecision(10)
typedef long long int ll;
typedef std::pair<int,int> P;
int D=1;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//template<typename T>void pp(T x){cout<<x<<endl;}

using namespace std;
template<typename T> void test(vector<T> v){for(int i=0;i<v.size();i++){if(i)cout<<" ";cout<<v[i];}cout<<endl;}

int main(){
    int n,l,r;
    while(cin>>n>>l>>r&&n&&l&&r){
        vector<int> v(n);
        rep(i,0,n)cin>>v[i];
        int ans=0;
        rep(i,l,r+1){
            bool flag=true;
            rep(j,0,n){
                if(i%v[j]==0){
                    flag=false;
                    if(j%2==0)ans++;
                    break;
                }
            }
            if(flag&&n%2==0)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
} 
