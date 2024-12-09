#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

void show(int e, int m){
    string s = "";
    rep(i,12){
        s = char('0'+e%2) + s;
        e /= 2;
    }
    cout << s;
    for(int i = 51; i >= 0; i--)cout << ((m >> i)&1);
    cout << endl;
}
signed main(void) {
    int n;
    while(cin >> n,n){
        string s;
        cin >> s;
        int e = 0;
        int m = 1;
        rep(i,52){
            m *= 2;
            m += s[i] == '1';
        }
        int a = m;
        while(n && a){
            int left = (1LL<<53) - m;
            int num = left/a + !(left % a == 0);
            if(n < num){
                num = n;
                m += a*num;
            }else{
                e++;
                m += a*num;
                m = m >> 1;
                a = a >> 1;
            }
            n -= num;
        }
        show(e,m);
    }
}

