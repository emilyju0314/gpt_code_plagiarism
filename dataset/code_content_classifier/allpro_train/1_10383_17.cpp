#include <iostream>
#include <cmath>
#include <string>
#include <complex>

using namespace std;

#define rep(i,b) for(int i=0; i<b; i++)

typedef complex<int> P;

int w,h;

inline bool in(P const& p){
    return 1<=p.real() && p.real() <= w && 1<=p.imag() && p.imag() <= h;
}

int main(){
    while(cin>>w>>h, w|h){
        P cur = P(1,1);
        P d = P(0,1);
        while(true){
            string s; cin>>s;
            char op = s[0];
            if(op=='S'){
                cout << cur.real() << ' ' << cur.imag() << endl;
                break;
            } else if(op == 'F' || op == 'B'){
                P b = op == 'F' ? P(1,0) : P(-1,0);
                int k; cin>>k;
                rep(i,k){
                    P next = cur+d*b;
                    if(in(next)) cur = next;
                    else break;
                }
            } else if(op == 'R'){
                d/=P(0,1);
            } else if(op == 'L'){
                d*=P(0,1);
            }
        }
    }
}