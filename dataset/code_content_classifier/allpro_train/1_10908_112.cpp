#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

    while(1){
        int n, m, q; cin >> n >> m >> q;
        if(!n) break;

        vector<vector<bool> > a(n, vector<bool> (m, true));

        vector<string> s(q + 1);
        vector<string> t(q + 1);        

        for(int i = 0; i < n; i++) s[0] += '0';
        for(int i = 0; i < m; i++) t[0] += '0';


        for(int i = 1; i <= q; i++){
            cin >> s[i] >> t[i];

            //押して、変化なし　|| 押さずに変化ありをfalseに
            for(int j = 0; j < n; j++){

                for(int k = 0; k < m; k++){                    
                    if((s[i][j] == '1' && (t[i][k] == t[i-1][k])) || s[i][j] == '0' && (t[i][k] != t[i-1][k])) a[j][k] = false; 
                }
                
            }
        
        }


        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[i][j] << " ";            
            }
            cout << endl;
        }*/

        string M = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        string ans;
        for(int i = 0; i < m; i++) ans += '?';
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[j][i] == true && ans[i] == '?') ans[i] = M[j];
                else if(a[j][i] == true && ans[i] != '?'){
                    ans[i] = '?';
                    //cout << i << " con" << endl;
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
