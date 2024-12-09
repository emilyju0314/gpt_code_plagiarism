#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        vvi vec(n,vi(m));
        string s;
        rep(i,n){
            cin >> s;
            rep(j,m){
                vec[i][j] = s[j]-'0';
            }
        }
        int ans = 0;
        if(n <= 18){
            rep(i,(1 << n)){
                vi v(m,0);
                rep(j,n){
                    if((i >> j)&1){
                        rep(k,m){
                            v[k] ^= vec[j][k];
                        }
                    }
                }
                bool flag = true;
                rep(j,m){
                    if(v[j] != 0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cmx(ans,__builtin_popcount(i));
                }
            }
            cout << ans << "\n";
        }else{
            vl val(n);
            rep(i,n){
                // svec(vec[i]);
                rep(j,m){
                    val[i] += ((ll)vec[i][j] << j);
                }
            }
            // svec(val);
            map<ll,int> mp;
            mp[0] = 0;
            rep(i,n){
                map<ll,int> mp2;
                each(it,mp){
                    mp2[it.fi] = max(mp[it.fi],mp2[it.fi]);
                    mp2[it.fi^val[i]] = max(it.se+1,mp2[it.fi^val[i]]);
                }
                mp = mp2;
            }
            cout << mp[0] << "\n";
        }
    }
    return 0;
}

