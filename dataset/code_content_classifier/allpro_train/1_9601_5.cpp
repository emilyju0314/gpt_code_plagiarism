#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> P;
vector<P> V;
const int MAX_N=100000;
int C[MAX_N];
bool b[MAX_N];

int main(){
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<Q;i++){
        int A,B;
        cin>>A>>B;
        A--;B--;
        V.emplace_back(A,B);
    }
    for(int i=0;i<N;i++){
        C[i]=i;
    }
    for(int i=Q-1;i>=0;i--){
        int A=V[i].first, B=V[i].second;
        swap(C[A],C[B]);
    }
    int p=0;
    b[C[p]]=true;
    b[C[p+1]]=true;
    for(int i=0;i<Q;i++){
        int A=V[i].first, B=V[i].second;
        if(A==p){
            p=B;
        }else if(B==p){
            p=A;
        }
        swap(C[A],C[B]);
        if(p>0){
            b[C[p-1]]=true;
        }
        if(p<N-1){
            b[C[p+1]]=true;
        }
    }
    int ans=0;
    for(int i=0;i<N;i++){
        if(b[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}