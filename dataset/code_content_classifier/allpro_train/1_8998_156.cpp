#include <bits/stdc++.h>

using namespace std;
using P=pair<int,int>;
using PP=pair<P,int>;

int main(){
    int n;
    while(cin>>n,n){
        vector<PP>data;
        for(int j=0;j<n;++j){
            char c;cin>>c;
            if(c=='W'){
                int l,s;cin>>l>>s;
                int siz=data.size();
                if(siz==0)data.push_back(PP(P(0,s),l));
                for(int i=0;i<siz;++i){
                    if(data[i].second==-1){
                        if(s>=data[i].first.second-data[i].first.first){
                            s-=(data[i].first.second-data[i].first.first);
                            data[i].second=l;
                            if(!s)break;
                        }else{
                            data.push_back(PP(P(data[i].first.first,data[i].first.first+s),l));
                            data[i].first.first+=s;
                            s=0;
                            break;
                        }
                    }
                    if(i==(siz-1)){
                        data.push_back(PP(P(data[i].first.second,data[i].first.second+s),l));
                        s=0;
                    }
                }
                sort(data.begin(),data.end());
            }else if(c=='D'){
                int l;cin>>l;
                for(int i=0;i<data.size();++i){
                    if(data[i].second==l){
                        data[i].second=-1;
                    }
                }
            }else{
                int p,ans=-1;cin>>p;
                for(int i=0;i<data.size();++i){
                    if(data[i].first.first<=p && data[i].first.second>p){
                        ans=data[i].second;
                        break;
                    }
                }
                cout<<ans<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}