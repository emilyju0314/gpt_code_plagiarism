#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
typedef long long LL;
typedef pair<LL, LL> P;
 
int main() {
    LL a, c;
    LL b;
    cin >> a >> b >> c;
 
    P m[100005];
    P q[1010];
    vector<LL>st;
 
    for (LL i = 0;i < a;i++)cin >> m[i].first >> m[i].second;
    
    for (LL i = 0;i < c;i++) {
        LL d;
        cin >> d;
        q[i] = m[d - 1];
    }
 
    for (LL i = 0;i < a - 1;i++) {
        if (m[i].second == 1 && m[i + 1].second == 2)st.push_back((m[i].first + m[i+1].first) / 2);
    }
 
 
    for (LL i = 0;i < c;i++) {
 
        if (q[i].second == 1) {
 
            long long e = q[i].first+b;
 
            for (int j = 0;j < st.size();j++) {
 
                if (q[i].first < st[j]) {
                    if (e>= st[j])e = st[j];
                }
 
            }
            cout << e << endl;
        }
 
        else {
 
            long long e=q[i].first-b;
 
            LL f = st.size();
            for (LL j = f - 1;j > -1;j--) {
 
                if (q[i].first > st[j]) {
                    if (e <= st[j])e = st[j];
                }
                 
            }
            cout << e << endl;
        }
        
    }
   
    return 0;
}