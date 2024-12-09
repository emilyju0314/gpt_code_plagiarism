#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9)
#define ALL(x) (x).begin(),(x).end()
#define ctoi(x) (x - 'a') 
#define CTOI(x) (x - 'A')
using namespace std;
int main(){
    int N;
    cin >> N;
    int sum = 0;
    int ans = 100000;
    REPA(i,N+1){
        int d;
        cin >> d;
        sum += d;
        ans = min(sum / i,ans);
    }
    cout << ans << endl;
    return 0;
}

