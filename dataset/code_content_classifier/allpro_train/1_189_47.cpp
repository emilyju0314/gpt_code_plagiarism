#include<iostream>
using namespace std;
/******************** Beginning of Template **************************/
/************ ALL HEADER FILE ***********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
/************************************ ALL DEFINE ****************************************************/
#define repstep(i, j, k, step) for (int i=j; i<k; i+=step)
#define rep(i, j, k) for (int i=j; i<k; i++)
#define dsrep(i, j, k, step) for (int i=j; i>=k; i-=step)
#define drep(i, j, k) for(int i=j; i>=k; i--)
#define srep(i, k) for(int i = (0); i < (k); i++ )
 #define sdrep(i, k) for(int i = j; i >= (k); i-- )
 //srep==simple repetition.
#define sbko(cont) cont.begin(), cont.end()
//#define RALL(cont) cont.begin(), cont.end()
#define every(l) for(auto it=l.begin(); it != l.end(); it++)
#define mp make_pair
#define pb push_back
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF (int)MAX_INT
#define EPS (int)1e-9
#define PI acos(-1)
#define MOD 1000000007
#define fango using
#define ganteng namespace
#define sekali std
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x,y) cout<<#x<<" = "<<x<<#y<<" = "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" = "<<x<<#y<<" = "<<y<<#z<<" = "<<z<<endl;
#define deb4(x,y,z,n) cout<<#x<<" = "<<x<<#y<<" = "<<y<<#z<<" = "<<z<<" "<<#n<<"=  "<<n<<endl;
#define deb5(x,y,z,n,n2) cout<<#x<<" = "<<x<<#y<<" = "<<y<<#z<<" = "<<z<<" "<<#n<<"=  "<<n<<" "<<#n2<<" = "<<n2<<endl;
/************************************ END OF DEFINE ****************************************************/
 
/************************************ ALL TYPEDEF ****************************************************/
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> grp;
typedef vector<piii> viii;
typedef long long int32;
typedef unsigned long long uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
 
void swap(int *a,int *b)
{
      int c=*a;
      *a=*b;
      *b=c;
}
 int abs(int a)
  {
        if(a>0)
	return a;
	else
	return -a;
  }
void  solve()
     {
         long long int ans=0;

          string s;  cin>>s;
   
            for(int i=1;i<s.length();i++)
            {
                       if(s[i]==s[i-1])
                       {
                             s[i]='0'; ans++;
                       }  
                       else if (i-2>-1 && s[i]==s[i-2])
                       {
                              s[i]='0'; ans++;
                       }
                         



            }
    cout<<ans<<endl;
     }

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
  int t; cin>>t; while (t--) solve();
                  
     
   return 0;
 
}
