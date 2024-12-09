#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int INF=1000000000;
char chs[1001];

int main(){
    bool fi=false;
    string str;
    while(getline(cin,str)&&str!=""){
        memset(chs,0,sizeof(chs));
        string ss;
        string tmp;
        if(fi)cout<<endl;
        else fi=true;
        while(getline(cin,tmp)&&tmp!="")str+=tmp;
        while(getline(cin,tmp)&&tmp!="")ss+=tmp;
        int sz=INF;
        int optHead=0;
        int optTail=0;
        int head=0;
        int tail=-1;
        int cnt=0;
        while(tail<(int)str.size()){
            bool ok=true;
            for(int i=0;i<ss.size();i++)if(chs[ss[i]]<=0)ok=false;
            // ツ個サツ催敖づ個氾債暗債つェツ適ツ静伉づ按づァ
            if(ok){
                if(tail-head+1<sz){
                    optHead=head;
                    optTail=tail;
                    sz=tail-head+1;
                    cnt=1;
                }
                else if(tail-head+1==sz)cnt++;
                chs[str[head]]--;
                head++;
            }
            else{
                tail++;
                if(tail<(int)str.size())chs[str[tail]]++;
            }
        }
        cout<<cnt<<endl;
        if(cnt!=0){
            cout<<endl;
            for(int i=optHead;i<optHead+sz;i++){
                int cn=i-optHead+1;
                cout<<str[i];
                if(cn%72==0||i==optHead+sz-1)cout<<endl;
            }
        }
    }
    cout<<endl;
    return 0;
}