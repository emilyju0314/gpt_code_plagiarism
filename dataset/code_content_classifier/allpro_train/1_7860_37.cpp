#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    sort(a,a+N,greater<int>());
    int x=1e9+1;
    int ans;
    for(int i=1;i<N;i++){
        if(x>abs(a[0]/2-a[i])){
            x=abs(a[0]/2-a[i]);
            ans=a[i];
        }
    }
    cout << a[0] << ' ' << ans << endl;
}