#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    int min_wait = INT_MAX;
    int best_route = -1;

    for(int i=0; i<n; i++){
        int s, d;
        cin >> s >> d;
        if(s >= t){
            if(s-t < min_wait){
                min_wait = s-t;
                best_route = i+1;
            }
        }else{
            int wait = d - ((t-s)%d);
            if(wait < min_wait){
                min_wait = wait;
                best_route = i+1;
            }
        }
    }

    cout << best_route << endl;
    return 0;
}