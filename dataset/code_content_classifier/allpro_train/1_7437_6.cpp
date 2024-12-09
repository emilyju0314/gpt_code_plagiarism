#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define en "\n"
using ll=long long;
template<class T> using vec=vector<T>;
template<class T> using vvec=vec<vec<T>>;
using P=pair<ll,ll>;

ll n;

typedef pair<ll, ll> result;
#define value first
#define p second

result equation(const string &s, int p = 0);
pair<result,vec<ll>> factor(const string &s, int p = 0);
result term(const string &s, int p = 0);

ll ans;

void cal(vvec<ll>& data){
    ll lt=0,lf=0,rt=0,rf=0;
    ll val=0;
    ll base=1;
    vec<ll> mul(data.size()+1,0);

    while(rf<data.size()){
        while(data[lf][lt]==1 && lt+1<data[lf].size()){
            //1*のときは重複を数える(baseで管理)
            lt++;
            base++;
            if(lf==rf && lt>rt)rt++;
        }

        if(data[rf][rt]>n){
            //n以上の場合は飛ばす
            rt++;
            if(rt == data[rf].size()){
                rt=0;
                rf++;
            }
            lt=rt;
            lf=rf;
            val=0;
            mul[lf] = 0;
            base=1;
            continue;
        }

        //右に進める処理
        if(mul[rf]==0){
            mul[rf]=data[rf][rt];
            val+=data[rf][rt];
        }else{
            val+=mul[rf]*data[rf][rt]-mul[rf];
            mul[rf]*=data[rf][rt];
        }
        rt++;
        if(rt==data[rf].size()){
            rf++;
            rt=0;
        }

        //左を進める処理
        if(val>n){
            base=1;
            //超えてる間左を詰める
            while(val>n){
                if(lt==data[lf].size()-1){
                    mul[lf]=0;
                    val-=data[lf][lt];
                    lf++;
                    lt=0;
                }else{
                    val-=mul[lf]-mul[lf]/data[lf][lt];
                    mul[lf]/=data[lf][lt];
                    lt++;
                }
            }

            //1*の重複処理
            bool flag=false;
            while(data[lf][lt]==1 && lt+1<data[lf].size()){
                //1*のときは重複を数える(baseで管理)
                lt++;
                base++;
                if(lf==rf && lt>rt){
                    //lがrを超えちゃった時は、rをすすめて次の処理に
                    rt++;
                    flag=true;
                }
            }
            if(flag){
                //rをすすめた場合は再計算
                val=0;
                mul[lf]=0;
                continue;
            }
        }
        
        //値がぴったりになったら重複分も合わせて足す
        if(val==n) ans+=base;
    }
}

void cal1(vvec<ll> data){
    for(auto i:data){
        ll con=0;
        for(auto j:i){
            if(j==1){
                con++;
                ans+=con;
            }else{
                con=0;
            }
        }
    }
}

result equation(const string &s, int p) {
    vvec<ll> data;
    auto ret = factor(s, p);
    result r=ret.first;
    data.push_back(ret.second);
    while (s[r.p] == '+') {
        auto ret_ = factor(s, r.p+1);
        result r_ = ret_.first;
        r.value = min(n+1,r.value + r_.value);
        r.p = r_.p;
        data.push_back(ret_.second);
    }
    if(n==1) cal1(data);
    else if(r.value >=n) cal(data);
    return r;
}

pair<result,vec<ll>> factor(const string &s, int p) {
    vec<ll> ret;
    result r = term(s, p);
    ret.push_back(r.value);

    while (s[r.p] == '*') {
        result r_ = term(s, r.p+1);
        r.value = min(n+1,r.value * r_.value);
        r.p = r_.p;
        ret.push_back(r_.value);
    }
    return {r,ret};
}

result term(const string &s, int p) {
    if (s[p] == '(') {
        result r = equation(s, p+1);
        r.p += 1; // skip ')'
        return r;
    } else {
        int value = 0;
        while (isdigit(s[p]))
        value = value * 10 + (s[p++] - '0');
        return result(value, p);
    }
}

void solve(){
    string s;
    cin>>s;
    ans=0;
    result r=equation(s);
    cout<<ans<<en;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n){
        if(n==0) break;
        else solve();
    }
    return 0;
}
