#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int Q, L;
    /* 00.51sec 
    while(scanf("%d %d", &Q, &L) != EOF && Q > 0){
        deque<int> deq;
        for(int q, x; Q--;){
            scanf("%d %d", &q, &x);
            while(deq.size() > L) deq.pop_front();
            if(q == 0) deq.push_back(x);
            if(q == 1) deq.erase(deq.begin() + x - 1);
            if(q == 2) printf("%d\n", deq[x - 1]);
            if(q == 3) deq.erase(find(deq.begin(), deq.end(), x));
        }
        puts("end");
    }
    */
    while(scanf("%d %d", &Q, &L) != EOF && Q > 0){
        vector<int> vec;
        for(int q, x; Q--;){
            scanf("%d %d", &q, &x);
            while(vec.size() > L) vec.erase(vec.begin());
            if(q == 0) vec.push_back(x);
            if(q == 1) vec.erase(vec.begin() + x - 1);
            if(q == 2) printf("%d\n", vec[x - 1]);
            if(q == 3) vec.erase(find(vec.begin(), vec.end(), x));
        }
        puts("end");
    }
    return 0;
}