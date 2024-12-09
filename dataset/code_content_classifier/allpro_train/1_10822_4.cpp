#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

void input(char *a, int *al, int &an){
    while(true){
        scanf(" %c", &a[an]);
        if(a[an] == '$') break;
        scanf("%d", &al[an++]);
    }
}

void push(deque<pair<char, int>> &dq, pair<char, int> p){
    if(p.se == 0) return;
    else if(!dq.empty() && dq.rbegin()->fi == p.fi) dq.rbegin()->se += p.se;
    else dq.push_back(p);
}

int main(){
    char a[1010], b[1010], c[1010];
    int al[1010], bl[1010], cl[1010];
    int an = 0, bn = 0, cn = 0;
    input(a, al, an);
    input(b, bl, bn);
    input(c, cl, cn);

    deque<pair<char, int>> dq;
    if(bn == 1){
        rep(i, an)if(a[i] == b[0] && al[i] >= bl[0]){
            al[i] -= bl[0];
            rep(j, i) push(dq, {a[j], al[j]});
            rep(j, cn) push(dq, {c[j], cl[j]});
            For(j, i, an) push(dq, {a[j], al[j]});
            break;
        }
    }
    else{
        rep(i, an)if(a[i] == b[0] && al[i] >= bl[0] && a[i+bn-1] == b[bn-1] && al[i+bn-1] >= bl[bn-1]){
            bool flag = true;
            For(j, 1, bn-1)if(a[i+j] != b[j] || al[i+j] != bl[j]){
                flag = false;
                break;
            }
            if(flag){
                al[i] -= bl[0];
                al[i+bn-1] -= bl[bn-1];
                rep(j, i+1) push(dq, {a[j], al[j]});
                rep(j, cn) push(dq, {c[j], cl[j]});
                For(j, i+bn-1, an) push(dq, {a[j], al[j]});
                i = MAX;
                break;
            }
        }
    }

    if(!dq.empty()){
        for(auto p: dq) printf("%c %d ", p.fi, p.se);
    }
    else{
        rep(i, an) printf("%c %d ", a[i], al[i]);
    }
    printf("%c\n", '$');
}
