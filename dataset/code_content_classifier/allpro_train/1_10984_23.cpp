#include <iostream>
#include <map>
#include <utility>
using namespace std;
struct line{
    int type;
    int con;
    char c[3];
};
const int N=100;
int main(){
    int n,t,cnt=0,temp;
    map<int,int> m;
    map<char,int>var;
    line a[N];
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        m.insert({t,i});
        cin>>s;
        if(s[0]=='H')a[i].type=0;
        else if(s[0]=='A'){
            cin>>s;
            var.insert({s[0],0});
            a[i].c[0]=s[0];
            cin>>s;
            var.insert({s[0],0});
            a[i].c[1]=s[0];
            cin>>s;
            if('a'<=s[0]&&s[0]<='z'){
                var.insert({s[0],0});
                a[i].c[2]=s[0];
                a[i].type=1;
            }
            else{
                t=0;
                for(char j:s){
                    t*=10;
                    t+=j-'0';
                }
                a[i].type=2;
                a[i].con=t;
            }
        }
        else if(s[1]=='E'){
            cin>>s;
            var.insert({s[0],0});
            a[i].c[0]=s[0];
            cin>>s;
            if('a'<=s[0]&&s[0]<='z'){
                var.insert({s[0],0});
                a[i].c[1]=s[0];
                a[i].type=3;
            }
            else{
                t=0;
                for(char j:s){
                    t*=10;
                    t+=j-'0';
                }
                a[i].type=4;
                a[i].con=t;
            }
        }
        else if(s[0]=='I'){
            cin>>s;
            var.insert({s[0],0});
            a[i].c[0]=s[0];
            cin>>a[i].con;
            a[i].type=7;
        }
        else{
            cin>>s;
            var.insert({s[0],0});
            a[i].c[0]=s[0];
            cin>>s;
            var.insert({s[0],0});
            a[i].c[1]=s[0];
            cin>>s;
            if('a'<=s[0]&&s[0]<='z'){
                var.insert({s[0],0});
                a[i].c[2]=s[0];
                a[i].type=5;
            }
            else{
                t=0;
                for(char j:s){
                    t*=10;
                    t+=j-'0';
                }
                a[i].type=6;
                a[i].con=t;
            }
        }
    }
    t=0;
    while(cnt<2e8){
        cnt++;
        if(t>=n||a[t].type==0)break;
        else if(a[t].type==1){
            temp=var[a[t].c[1]]+var[a[t].c[2]];
            if(temp<0||temp>=16)break;
            var[a[t].c[0]]=temp;
        }
        else if(a[t].type==2){
            temp=var[a[t].c[1]]+a[t].con;
            if(temp<0||temp>=16)break;
            var[a[t].c[0]]=temp;
        }
        else if(a[t].type==3){
            temp=var[a[t].c[1]];
            if(temp<0||temp>=16)break;
            var[a[t].c[0]]=temp;
        }
        else if(a[t].type==4){
            temp=a[t].con;
            if(temp<0||temp>=16)break;
            var[a[t].c[0]]=temp;
        }
        else if(a[t].type==5){
            temp=var[a[t].c[1]]-var[a[t].c[2]];
            if(temp<0||temp>=16)break;
            var[a[t].c[0]]=temp;
        }
        else if(a[t].type==6){
            temp=var[a[t].c[1]]-a[t].con;
            if(temp<0||temp>=16)break;
            var[a[t].c[0]]=temp;
        }
        else{
            if(var[a[t].c[0]]!=0){
                if(m.find(a[t].con)==m.end())break;
                else {
                    t=m[a[t].con];
                    continue;
                }
            }
        }
        t++;
    }
    if(cnt>=2e8)cout<<"inf"<<endl;
    else for(pair<char,int> i:var)cout<<i.first<<"="<<i.second<<endl;
}
