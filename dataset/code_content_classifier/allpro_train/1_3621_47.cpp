#include <bits/stdc++.h>

#define FOR(i,n)    for(lli i=0;i<(lli)(n);++i)
#define FORU(i,j,k) for(lli i=(j);i<=(lli)(k);++i)
#define FORD(i,j,k) for(lli i=(j);i>=(lli)(k);--i)

#define pb push_back
#define mt make_tuple

using namespace std;

using lli = long long int;
using pll = pair<lli, lli>;

using vi = vector<lli>;
using vvi = vector<vi>;
using pii = tuple<lli, lli>;
using vii = vector<pii>;
using vvii = vector<vii>;

#define X(a) get<0>(a)
#define Y(a) get<1>(a)
#define Z(a) get<2>(a)

string TYPE(const int*)          { return "%d";   }
string TYPE(const lli*)          { return "%lld"; }
string TYPE(const char*)         { return "%c";   }
string TYPE(const char**)        { return "%s";   }
string TYPE(const unsigned int*) { return "%u";   }

const int MAX_BUF = 5*100*1000+42;
char buf[MAX_BUF];

void RD() {}
template<typename T, typename... Args> 
void RD(T* v, Args... args)
{
    scanf((" " + TYPE(v)).c_str(), v);
    RD(args...);
}
template<typename... Args> 
void RD(string* v, Args... args)
{
    scanf(" %s", buf);
    (*v) = buf;
    RD(args...);
}

void PR(bool nl = true)
{ if(nl) printf("\n"); }
template<typename T, typename... Args> 
void PR(bool nl, T v, Args... args)
{
    printf((TYPE(&v) + " ").c_str(), v);
    PR(nl, args...);
}
template<typename... Args> 
void PR(bool nl, string& v, Args... args)
{
    printf("%s", v.c_str());
    PR(nl, args...);
}
template<typename... Args> 
void PR(Args... args)
{ PR(true, args...); }

const long long int oo = 1000*1000*1000;

struct Coord {
    int x, y;
    Coord(int x = 0, int y = 0) : x(x), y(y) {}
    Coord operator + (const Coord& droite) const
    { return Coord(x + droite.x, y + droite.y); }
};

struct AB {
    int k; vector<lli> arbre;
    AB(int _k = 20, lli def = 0) { k = _k;
        FOR(i, 1 << k)
            arbre.push_back(i < (1 << (k-1)) ? 0LL : def);
        FORD(i, ((1 << (k-1)) - 1), 1)
            arbre[i] = arbre[i << 1] + arbre[(i << 1) ^ 1];
    }
    void set(int i, lli x) { int feuille = i + (1 << (k-1));
        arbre[feuille] = x;
        iset(feuille >> 1);
    }
    void iset(int noeud) {
        if(noeud) {
            arbre[noeud] = arbre[noeud << 1] + arbre[(noeud << 1)  ^ 1];
            iset(noeud >> 1);
    }   }
    lli sum(int deb, int fin, int noeud = 1, int p = 0, int q = -1) {
        if(q < p) q = 1 << (k-1);
        if(deb <= p && q <= fin) return arbre[noeud];
        if(deb >= q || fin <= p) return 0LL;
        int mil = (p + q) / 2;
        return sum(deb, fin, noeud << 1, p, mil) + sum(deb, fin, (noeud << 1) ^ 1, mil, q);
    }
};

string s;
int dyn[27][5*100*1000+42];
int suiv[5*100*1000+42];
vector<int> prec[5*100*1000+42];
int vin[5*100*1000+42], vout[5*100*1000+42];
bitset<5*100*1000+42> dejaVu;
int cur;

void dfs(int n)
{
    stack<int> pile;
    pile.push(n+1);
    do
    {
        if(pile.top() > 0)
        {
            int pos = pile.top()-1;
            //PR('i', pos);
            pile.pop();
            pile.push(-pos-1);
            assert(!dejaVu[pos]);
            dejaVu[pos] = true;
            vin[pos] = cur++;
            for(auto v : prec[pos])
                pile.push(v+1);
        }
        else
        {
            //PR('o', -pile.top()-1);
            vout[-pile.top()-1] = cur++;
            pile.pop();
        }
    } while (!pile.empty());
}

int main()
{
    RD(&s);
    int n = s.length();
    FOR(i, 26)
        dyn[i][n] = -1;
    dyn[26][n] = n;
    FOR(i, n)
        suiv[i] = -1;
    FORD(i, n-1, 0)
    {
        FOR(j, 27)
        {
            dyn[j][i] = -1;
            if(s[i]-'a' == j)
                dyn[j][i] = i;
            else if(s[i]-'a' < j)
            {
                int rjm = dyn[j-1][i];
                if(rjm != -1)
                {
                    int rjm2 = dyn[j-1][rjm+1];
                    if(rjm2 != -1)
                        dyn[j][i] = rjm2;
                }
            }
            //printf("%2d%c", dyn[j][i], " \n"[j==26]);
        }
        FOR(j, 26)
        {
            if(dyn[26][i] != -1 && dyn[j][i] == -1)
                dyn[j][i] = dyn[j][dyn[26][i]+1];
        }
        suiv[i] = dyn[26][i] == -1 ? -1 : dyn[26][i]+1;
        if(suiv[i] != -1)
            prec[suiv[i]].push_back(i);
    }
    //FOR(i, n)
    //{
    //    PR(false, i, ':');
    //    FOR(j, (int)prec[i].size())
    //        PR(false, prec[i][j]);
    //    PR();
    //}
    FORD(i, n, 0)
        if(!dejaVu[i])
            dfs(i);
    //FOR(i, n)
    //    PR(vin[i], vout[i]);
    int q;
    RD(&q);
    FOR(iq, q)
    {
        int a, b;
        RD(&a, &b);
        --a;
        PR(vin[b] <= vin[a] && vout[a] <= vout[b] ? "Yes" : "No");
    }
    return 0;
}
