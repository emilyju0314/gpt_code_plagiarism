#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
typedef complex<D> P;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,vector<T> &A){ll i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}
template<typename T>vector<T> & cset(vector<T> &A,T e=T()){for(auto &I:A){I=e;} return A;}

const ll NUM=26;
const ll SIZE=52;

ll cul(char c){return islower(c)?c-'a':c-'A'+NUM;}


int main(){
    string s;
    while(cin>>s,s[0]!='#'){
        ll N=s.size();
        vector<vector<bool>> A(SIZE,vector<bool>(SIZE));
        bool db=false;
        for(int i=1;i<N;i++){db|=A[cul(s[i-1])][cul(s[i])]; A[cul(s[i-1])][cul(s[i])]=true;}
        vector<ll> Icnt(SIZE,0),Ocnt(SIZE,0);
        ll rem=0,num=0,mx=0;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                num+=A[i][j];
                Icnt[j]+=A[i][j];
                Ocnt[i]+=A[i][j];
            }
        }
        for(int i=0;i<SIZE;i++){
            rem+=max(0LL,Icnt[i]-Ocnt[i]);
            mx=max(mx,Ocnt[i]);
            mx=max(mx,Icnt[i]);
        }
        ll B=cul(s[0]),G=cul(s.back());
        ll add=max(0LL,rem-1)+1;
        if(num+add<N){cout<<num+add<<endl;}
        else if(num<=1){cout<<"No Results"<<endl;}
        else if(db || mx>2 || B==G || Ocnt[G]>1 || Icnt[B]>1){cout<<N<<endl;}
        else{
            function<bool(int,int)> check=[&](int w,int p){
                vector<bool> used(SIZE,false);
                used[p]=true;
                used[w]=true;
                stack<int> S;
                S.push(w);
                while(!S.empty()){
                    w=S.top(); S.pop();
                    if(w==G){return true;}
                    for(int j=0;j<SIZE;j++){
                        if(!used[j] && A[w][j]){S.push(j); used[j]=true;}
                    }
                }
                return false;
            };
            mx=0;
            for(int i=0;i<SIZE;i++){
                int cnt=0;
                for(int j=0;j<SIZE;j++){
                    if(i!=j && A[i][j] && check(j,i)){cnt++;}
                }
                mx=max<ll>(mx,cnt);
            }
            cout<<(mx>=2?N:N+1)<<endl;
        }
    }
    
    
    return 0;
}

