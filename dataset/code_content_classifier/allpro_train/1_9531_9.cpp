#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> P3;
typedef pair<P ,P> PP;
constexpr ll MOD = 998244353;
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e6) + 5;
constexpr double EPS = 1e-8;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

using Real = double;
//using Complex = complex<Real>;

struct Complex{
    Real x, y;
    Complex():x(0),y(0){};
    Complex(Real x, Real y):x(x),y(y){};
};

inline Complex conj(Complex a){
    return Complex(a.x, -a.y);
}
inline Complex operator+(Complex a, Complex b){
    return Complex(a.x+b.x, a.y+b.y);
}
inline Complex operator-(Complex a, Complex b){
    return Complex(a.x-b.x, a.y-b.y);
}
inline Complex operator*(Complex a, Complex b){
    return Complex(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);
}
inline Complex operator/(Complex a, Complex b){
    Complex tmp = a*conj(b);
    return Complex(tmp.x/(b.x*b.x+b.y*b.y), tmp.y/(b.x*b.x+b.y*b.y));
}

const Real PI = acos(-1);

// W[i][j] = exp(root(-1)*2*PI*j/(2^i))
vector<vector<Complex>> W;

void init(int n){
    int h = 0;
    for(int i=0;1<<i<n;i++) h++;
    W.resize(h);
    for(int i=0;1<<i<n;i++){
        int d = 1<<i;
        W[i].resize(d*2+1);
        for(int j=0;j<=d*2;j++){
            if((j&1) || i==0){
                Real theta = 2*PI/(d*2)*j;
                W[i][j] = Complex(cos(theta), sin(theta));
            }
            else{
                W[i][j] = W[i-1][j>>1];
            }
        }
    }
}

vector<Complex> FFT(vector<Complex> a, bool rev = false){
    int n = a.size();
    int h = 0;
    for(int i=0;1<<i<n;i++) h++;
    // bitを逆転させ対応する位置とswap
    for(int i=0;i<n;i++){
        int j = 0;
        for(int k=0;k<h;k++){
            j |= (i>>k&1) << (h-1-k);
        }
        if(i<j) swap(a[i], a[j]);
    }
    
    for(int i=0;1<<i<n;i++){
        int d = 1<<i;
        for(int k=0;k<n;k+=d*2){
            for(int j=0;j<d;j++){
                Complex s = a[j+k+0];
                Complex t = a[j+k+d]*W[i][rev?j:d*2-j];
                a[j+k+0] = s+t;
                a[j+k+d] = s-t;
            }
        }
    }
    if(rev) for(int i=0;i<n;i++) a[i] = a[i]/Complex(n,0);
    return a;
}

vector<Complex> convolute(vector<Complex> &a, vector<Complex> &b){
    int deg = int(a.size() + b.size()) - 1;
    int n = 1;
    while(n < deg) n <<= 1;
    a.resize(n); b.resize(n);
    init(n);

    vector<Complex> inversed_a = FFT(a);
    vector<Complex> inversed_b = FFT(b);
    vector<Complex> inversed_c(n);

    for(int i=0;i<n;i++){
        inversed_c[i] = inversed_a[i] * inversed_b[i];
    }
    vector<Complex> c = FFT(inversed_c, true);
    return c;
}


vector<Complex> a, b;

int main(){
    string A, B;
    cin >> A >> B;
    int minus = 0;
    if(A.front() == '-'){
        minus ^= 1;
        A.erase(A.begin());
    }
    if(B.front() == '-'){
        minus ^= 1;
        B.erase(B.begin());
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int n = A.size(), m = B.size();
    a.resize(n+1);
    b.resize(m+1);
    for(int i=0;i<n;i++){
        a[i] = Complex(A[i]-'0',0);
    }
    for(int i=0;i<m;i++){
        b[i] = Complex(B[i]-'0',0);
    }
    auto c = convolute(a,b);
    vector<ll> C(c.size()*2);
    for(int i=0;i<c.size();i++){
        C[i] += ll(c[i].x+0.1);
    }
    int L = 1;
    for(int i=0;i<C.size();i++){
        if(C[i] >= 10){
            C[i+1] += C[i]/10;
            C[i] %= 10;
        }
        if(C[i] > 0) L = i+1;
    }
    if(minus && !(L==1 && C[0]==0)) cout << '-';
    for(int i=0;i<L;i++){
        cout << C[L-i-1];
    }
    cout << endl;
    return 0;
}

