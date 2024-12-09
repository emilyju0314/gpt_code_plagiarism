#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,N,j) for(int i = (N-1);i >= (j);i--)
#define _rec(i,N,j) for(int i = (N);i >=(j);i--)
#define ALL(x) x.begin(),x.end()
#define MEM(a,n) memset(a,n,sizeof(a))
#define fst first
#define scd second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int get_int(){int x;scanf("%d",&x);return x;}
LL get_ll(){LL x;scanf("%lld",&x);return x;}
double get_db(){double x;scanf("%lf",&x);return x;}

template<typename T> int chmin(T &a,T b){if(a > b){a = b;return 1;}else return 0;}
template<typename T> int chmax(T &a,T b){if(a < b){a = b;return 1;}else return 0;}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {_for(i,0,v.size()) os << v[i] << " ";return os;}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){for(auto a:v) os << a <<" ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){os << v.fst <<" "<<v.scd << " ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const map<T1,T2>& v){for(auto a:v) cout << a << endl;return os;}

static const int dx[8] = { -1,  0, 1, 0,  1, -1,  1, -1};
static const int dy[8] = {0,  1, 0,  -1,  1, -1, -1,  1};
const double pi  = acos(-1.0);
const double eps = 1e-8;
const LL  INF  = 0x3f3f3f3f3f3f3f3f;
const int inf = 1e9+7;

LL maxn = 1e18;

LL sum[70][10];

LL mypow(LL a,LL b){
    if(b < 0) return 0;
    return pow(a,b)+0.5;
}

void solve2(int first,int second,int digit,LL kth){
    printf("%d",second);
    if(first > second) swap(first,second);

    for(int i = digit; i > 0;i--){
        LL num = mypow(2,i - 1);
        if(kth > num){
            printf("%d",second);
            kth -= num;
        }
        else{
            printf("%d",first);
        }



    }


}

void solve(int first,int digit,LL kth){
    printf("%d",first);
    LL all = 9*(mypow(2,digit+1) - 1);
    LL rest = 9*(mypow(2,digit));

    LL ff = all - rest;
    LL sum = 0;
    _rep(i,0,9){
        if(i != first){
            if(sum + mypow(2,digit) >= kth){
                solve2(first,i,digit,kth - sum);
                return;
            }
            else{
                sum += mypow(2,digit);
            }
        }
        else{
            if(sum + ff >= kth){
                solve(first,digit - 1,kth - sum);
                return;
            }
            else{
                sum += ff;
            }

        }
    }



}

int main()
{
    //freopen("D2","r",stdin);
    //freopen("out","w",stdout);

    LL temp = 1;
    sum[0][0] = 0;

    _for(k,0,69){
        temp *= 2;
        _rep(j,1,9){
            sum[k][j] = sum[k][j-1];
            sum[k][j] += 9*(temp-1);
        }
        sum[k+1][0] = sum[k][9];

        if(sum[k+1][0] > maxn) break;
    }

    LL n;
    while(scanf("%lld",&n) && n){
        int ok = 0;
        _for(k,0,69){
            _rep(j,1,9){
                if(sum[k][j] >= n){
                    solve(j,k,n - sum[k][j-1]);
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
        printf("\n");
    }

    return 0;
}

