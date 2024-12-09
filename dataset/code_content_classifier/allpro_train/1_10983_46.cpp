#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
int main(){
    string str;
    while(getline(cin,str)){
        stringstream ss(str);
        vector<int>V;
        while(ss){
            int a;
            ss>>a;
            V.push_back(a);
        }
        if(V[0]==0)break;
        V.pop_back();
        stack<pair<int,int> >S;
        S.push(pair<int,int>(0,0));
        int Max=0;
        while(!S.empty()){
            int pnt=S.top().first,cnt=S.top().second;
            S.pop();
            if(pnt>21)continue;
            if(cnt==V.size()){
                Max=max(Max,pnt);
                continue;
            }
            int to=V[cnt];
            if(to>10)to=10;
            S.push(pair<int,int>(pnt+to,cnt+1));
            if(to==1)S.push(pair<int,int>(pnt+11,cnt+1));
        }
        cout<<Max<<endl;
    }
    return 0;
}