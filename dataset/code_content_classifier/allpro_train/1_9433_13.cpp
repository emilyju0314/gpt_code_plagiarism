#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> P(N),Q(N),F(N);
    for(int i=0;i<N;i++){
        cin >> P[i];
        Q[i] = P[i];
    }
    sort(Q.begin(),Q.end());
    for(int i=0;i<N;i++) cin >> F[i];
    sort(F.begin(),F.end());
    vector<int> ans(N);
    auto calc = [](vector<int>& A, vector<int>& B){
        int n = A.size(),m = B.size();
        assert(n==m);
        vector<int> cnt(n);
        int id = m-1;
        for(int i=n-1;i>=0;i--){
            while(id>=0 && B[id]>A[i]) id--;
            cnt[i] = m-1-id;
        }
/*         for(int i=0;i<n;i++){
            if(i>=2) cnt[i] += cnt[i-1];
            cerr << cnt[i] << (i!=n-1? " ":"\n");
        }
*/        int res = 0,add = 0;
        for(int i=n-1;i>=0;i--){
            res += (cnt[i]>=1);
            add += (cnt[i]>=1);
            if(i!=0) cnt[i-1] -= add;
        }
        return res;
    };
    int value = calc(Q,F);
//    cerr << value << endl;
      for(int i=0;i<N;i++){
        if(i==N-1){
            ans[i] = F[0];
            break;
        }
        int l = 0,r = F.size();
        while(l<F.size() && F[l]<=P[i]) l++;
        int id = 0;
        while(Q[id]!=P[i]) id++;
        Q.erase(Q.begin()+id);
        if(l!=(int)F.size()){
            while(l+1<r){
                int m = (l+r)/2;
                vector<int> a = Q,b = F;
                b.erase(b.begin()+m);
                if(value==calc(a,b)+1) l = m;
                else r = m;
            }
            vector<int> a = Q,b = F;
            b.erase(b.begin()+l); 
            if(calc(a,b)+1==value){
                ans[i] = F[l];
                value--;
            }else{
                if(l>0) l--;
                ans[i] = F[l];
            }
            F.erase(F.begin()+l);
        }else{
            l = 0,r = F.size();
            while(l+1<r){
                int m = (l+r)/2;
                vector<int> a = Q,b = F;
                b.erase(b.begin()+m);
                if(value==calc(a,b)) l = m;
                else r = m;
            }
            ans[i] = F[l];
            F.erase(F.begin()+l);
        }
    }
    for(int i=0;i<N;i++) cout << ans[i] << (i!=N-1? " ":"\n");
}
