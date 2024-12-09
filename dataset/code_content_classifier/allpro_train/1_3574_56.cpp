#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <utility> 
#include <string> 
#include <stack>
#include <set>

using namespace std; 
typedef long long ll;
set<int> st, stc;

bool checksym(int h1, int h2, int m1, int m2, int h, int m){
    if(stc.count(h1)){h1 = h1==2? 5:2;}
    if(stc.count(h2)){h2 = h2==2? 5:2;}
    if(stc.count(m1)){m1 = m1==2? 5:2;}
    if(stc.count(m2)){m2 = m2==2? 5:2;}
    if(st.count(h1) && st.count(h2) && st.count(m1) && st.count(m2) && ((m2*10 + m1)<h) && ((h2*10 + h1)<m)){
        return true;    
    }
    return false;
}

int main(){
    ll T;
    cin>>T;
    st.insert(0);
    st.insert(1);
    st.insert(2);
    st.insert(5);
    st.insert(8);
    stc.insert(2);
    stc.insert(5);
    while(T--){
        ll h, m, h1, h2, m1, m2;
        cin>>h>>m;
        string s;
        cin>>s;
        h1 = s[0]-'0';
        h2 = s[1]-'0';
        m1 = s[3]-'0';
        m2 = s[4]-'0';
        int cm = (h1*10 + h2)*m + m1*10 + m2;
        while(!checksym(h1,h2,m1,m2,h,m)){
            cm++;
            h1 = ((cm/m)%h)/10;
            h2 = ((cm/m)%h)%10;
            m1 = (cm%m)/10;
            m2 = (cm%m)%10;
        }
        cout<<h1<<h2<<":"<<m1<<m2<<endl;
   }
   return 0;
}