#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>

#define X first
#define Y second
#define PB push_back
#define INS insert

using namespace std;

typedef pair < int, int > pii;
typedef set<pii>::iterator iter;

const int N = 2e4 + 500;

set < pii > s;
stack < int > st;
int poz[N], fl = 0, bio[N], cur = 1, d = -1, n;

void dfs(int x){
    bio[x] = cur;
    int lo, hi;
    if(!fl){
        lo = poz[x] - d;
        hi = poz[x] + d;
    }
    else{
        lo = poz[x ^ 1] - d;
        hi = poz[x ^ 1] + d;
    }
    iter it = s.lower_bound({lo, 0});
    for(;it != s.end() && it->X <= hi;){
        if(it->Y == (x^1)) {
            it++;continue;
        }
        int nxt = it->Y;
        s.erase(it);
        dfs(nxt);
        if(!fl)
            it = s.lower_bound({poz[nxt ^ 1], nxt});
        else
            it = s.lower_bound({poz[nxt], nxt});
    }
    if(!fl) st.push(x);
}

bool sat2(){
    memset(bio, 0, sizeof(bio));
    fl = 0;cur = 1;
    for(int i = 0;i<2 * n;i++)
        s.insert({poz[i ^ 1], i});
    for(int i = 0;i<2 * n;i++){
        if(bio[i]) continue;
        s.erase({poz[i ^ 1], i});
        dfs(i);
    }
    s.clear();
    memset(bio, 0, sizeof(bio));
    for(int i = 0;i<2 * n;i++)
        s.insert({poz[i], i});
    fl = 1;cur = 1;
    while(!st.empty()){
        if(!bio[st.top()]){
            s.erase({poz[st.top()], st.top()});
            dfs(st.top());
            cur++;
        }
        st.pop();
    }
    s.clear();
    for(int i = 0;i<2 * n;i++){
        if(bio[i] == bio[i ^ 1])
            return 0;
    }
    return 1;
}


int main(){
    scanf("%d", &n);
    for(int i = 0;i<2 * n;i++){
        scanf("%d", poz + i);
    }
    for(int i = 29;i>=0;i--){
        d += (1 << i);
        if(sat2()) continue;
        d -= (1 << i);
    }
    printf("%d\n", d + 1);
}
