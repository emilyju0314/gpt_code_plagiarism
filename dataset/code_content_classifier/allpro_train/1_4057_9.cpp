#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
class key2{
public:
    string s,t;
    key2(string a,string b){
        if(a>b){
            swap(a,b);
        }
        s=a;
        t=b;
    }
};

bool operator<(const key2 &a,const key2 &b){
    return a.s<b.s||(a.s==b.s&&a.t<b.t);
}

class data{
public:
    string s,t;
    int num;
    data(key2 a,int b){
        s=a.s;
        t=a.t;
        num=b;
    }
    void out(){
        cout<<s<<" "<<t<<endl;
    }
};

int main(){
    int N,F;
    cin>>N>>F;
    map<key2,int> use;
    for(int i=0;i<N;++i){
        int time;
        cin>>time;
        vector<string> buylist(time);
        for(int j=0;j<time;++j){
            cin>>buylist[j];
        }
        for(int j=0;j<time;++j){
            for(int k=j+1;k<time;++k){
                key2 d(buylist[j],buylist[k]);
                map<key2,int>::iterator itr = use.find(d);
                if(itr==use.end()){
                    use[d]=1;
                }else{
                    ++use[d];
                }
            }
        }
    }
    int ans=0;
    vector<data> anslist;
    for(map<key2,int>::iterator itr=use.begin();itr!=use.end();++itr){
        if(itr->second>=F){
            anslist.push_back(data(itr->first,itr->second));
            ++ans;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;++i){
        anslist[i].out();
    }
}