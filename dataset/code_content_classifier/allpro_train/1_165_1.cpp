#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
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
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

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

#define getchar getchar_unlocked
#define putchar putchar_unlocked

int in() {
    int n, c;
    while ((c = getchar()) < '0') if (c == EOF) return -1;
    n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + c - '0';
    return n;
}

void out(int n) {
    int res[11], i = 0;
    do { res[i++] = n % 10, n /= 10; } while (n);
    while (i) putchar(res[--i] + '0');
    putchar('\n');
}

int n,K;
int x[MAX_N], g[MAX_N];

template<typename V> class BIT {
private:
    int n; vector<V> bit;
public:
    void add(int i,V x){ i++; while(i < n) bit[i] += x, i += i & -i;}
    V sum(int i){ i++; V s = 0; while(i>0) s += bit[i], i -= i & -i; return s;}
    BIT(){} BIT(int sz){ n = sz + 1, bit.resize(n,0);} //初期値がすべて0の場合
    BIT(vector<V> v){ n = (int)v.size()+1; bit.resize(n); rep(i,n-1) add(i,v[i]);}
    void print(){ rep(i,n-1)cout<<sum(i)-sum(i-1)<< " ";cout<<endl;}
    void print_sum(){ rep(i,n)cout<<sum(i-1)<<" ";cout<<endl;}	//-1スタート
};

ll inv_count()
{
    BIT<int> bt(n);
    ll ans = 0;
    rep(i,n){
        ans += i-bt.sum(x[i]);
        bt.add(x[i],1);
    }
    return ans;
}

template<typename T> class segtree {
private:
    int n,sz;
    vector<T> node;
public:
    segtree(int N) : sz(N){
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.assign(2*n,numeric_limits<T>::max());
        rep(i,sz){
            node[i+n] = x[i];
        }
        for(int i=n-1; i>=1; i--){
            node[i] = min(node[2*i],node[2*i+1]);
        }
    }
    void update(int k,T a)
    {
    	node[k+=n] = a;
    	while(k>>=1){
    		node[k] = min(node[2*k],node[2*k+1]);
    	}
    }
    T query(int a,int b)
    {
        T res1 = numeric_limits<T>::max();
        T res2 = numeric_limits<T>::max();
        a += n, b += n;
        while(a != b){
            if(a % 2) cmn(res1,node[a++]);
            if(b % 2) cmn(res2,node[--b]);
            a >>= 1, b>>= 1;
        }
        return min(res1, res2);
    }
    void print()
    {
        rep(i,sz){
            cout << query(i,i+1) << " ";
        }
        cout << endl;
    }
};

template<typename T> class segtree_ {
private:
    int n,sz;
    vector<T> node;
public:
    segtree_(vector<T>& v){
        sz = (int)v.size();
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.resize(2*n-1,0);
        rep(i,sz){
            node[i+n-1] = v[i];
        }
        for(int i=n-2; i>=0; i--){
            node[i] = node[i*2+1] + node[i*2+2];
        }
    }
    void update(int k)
    {
    	k += n-1;
    	node[k]--;
    	while(k>0){
    		k = (k-1)/2;
    		node[k] = node[2*k+1] + node[2*k+2];
    	}
    }
    T query(int a,int b,int k=0,int l=0,int r=-1){
        if(r < 0) r = n;
    	if(r <= a || b <= l){
    		return 0;
    	}
    	if(a <= l && r <= b){
    		return node[k];
    	}else{
    		T vl = query(a,b,2*k+1,l,(l+r)/2);
    		T vr = query(a,b,2*k+2,(l+r)/2,r);
    		return vl + vr;
    	}
    }
    //cri以上の値を持つ最小のインデックスを返す
    int query_(const int cri,int k=0,int l=0,int r=-1)
    {
        if(r < 0) r = n;
        if(r - l == 1){
            return k - n + 1;
        }
        if(node[2*k+1] > cri){
            return query_(cri,2*k+1,l,(l+r)/2);
        }else{
            return query_(cri-node[2*k+1],2*k+2,(l+r)/2,r);
        }
    }
    void print(){rep(i,sz)cout<<query(i,i+1)<<" ";cout << endl;}
};

int main()
{
    n = in(), K = in();
    rep(i,n){
        x[i] = in();
        --x[i];
        g[x[i]] = i;
    }
    ll res = inv_count();
    ll rem = res - K;
    vi hoge(n,1);
    segtree<int> sg(n);
    segtree_<int> bt(hoge);
    if(rem <= 0){
        rep(i,n){
            out(x[i]+1);
        }
        return 0;
    }
    // show(rem);
    vector<bool> used(n, false);
    rep(i,n){
        if(rem <= 0){
            rep(j,n){
                if(!used[x[j]]){
                    out(x[j]+1);
                }
            }
            break;
        }else{
            int id = n-1;
            if(rem < n-i){
                id = bt.query_(rem);
            }
            // show(id);
            int num = sg.query(0,id+1);
            // show(num);
            used[num] = true;
            out(num+1);
            // show(g[num]);
            rem -= bt.query(0, g[num]);
            // show(rem);
            sg.update(g[num],INF);
            bt.update(g[num]);
        }
    }
    return 0;
}

