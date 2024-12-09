#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)


int main(){
    int q;
    cin >> q;
    rep(zz,q){
        int a,b,c,d;
        int cnt = 0;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++){
                if(i%2==0&&j%2==1){

                }else{
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }


    return 0;
}
